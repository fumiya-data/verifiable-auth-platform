package app

import (
	"testing"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/engineclient"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/messages"
	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

type stubService struct {
	logoutResult engineclient.CommandResult[engineclient.EmptyData]
	logoutErr    error
}

func (s stubService) Register(loginID string, password string) (engineclient.CommandResult[engineclient.EmptyData], error) {
	return engineclient.CommandResult[engineclient.EmptyData]{}, nil
}

func (s stubService) Login(loginID string, password string) (engineclient.CommandResult[engineclient.EmptyData], error) {
	return engineclient.CommandResult[engineclient.EmptyData]{}, nil
}

func (s stubService) ChangePassword(oldPassword string, newPassword string) (engineclient.CommandResult[engineclient.EmptyData], error) {
	return engineclient.CommandResult[engineclient.EmptyData]{}, nil
}

func (s stubService) Logout() (engineclient.CommandResult[engineclient.EmptyData], error) {
	return s.logoutResult, s.logoutErr
}

func (s stubService) ShowAudit() (engineclient.CommandResult[engineclient.AuditData], error) {
	return engineclient.CommandResult[engineclient.AuditData]{}, nil
}

func (s stubService) ShowMetrics() (engineclient.CommandResult[engineclient.MetricsData], error) {
	return engineclient.CommandResult[engineclient.MetricsData]{}, nil
}

func TestHomeEnterRoutesToRegister(t *testing.T) {
	model := NewModel(types.AppConfig{EnginePath: "engine_cli.exe", DataDir: ".engine-data"}, stubService{})

	next, command := model.Update(tea.KeyMsg{Type: tea.KeyEnter})
	if command != nil {
		t.Fatalf("expected no command when routing to register")
	}

	updated := next.(Model)
	if updated.route != types.RouteRegister {
		t.Fatalf("expected route %q, got %q", types.RouteRegister, updated.route)
	}
}

func TestLogoutSelectionCreatesCommandAndClearsSessionOnSuccess(t *testing.T) {
	service := stubService{
		logoutResult: engineclient.CommandResult[engineclient.EmptyData]{
			Response: engineclient.Response[engineclient.EmptyData]{
				Ok:     true,
				Result: "success",
				Data:   &engineclient.EmptyData{},
			},
		},
	}

	model := NewModel(types.AppConfig{EnginePath: "engine_cli.exe", DataDir: ".engine-data"}, service)
	model.sessionHint = types.SessionHint{Authenticated: true, LoginID: "alice"}

	var teaModel tea.Model = model
	for range 3 {
		teaModel, _ = teaModel.(Model).Update(tea.KeyMsg{Type: tea.KeyDown})
	}

	teaModel, command := teaModel.(Model).Update(tea.KeyMsg{Type: tea.KeyEnter})
	if command == nil {
		t.Fatalf("expected logout command")
	}

	logoutMessage := command()
	finished, ok := logoutMessage.(messages.LogoutFinished)
	if !ok {
		t.Fatalf("expected LogoutFinished message, got %T", logoutMessage)
	}

	if finished.Err != nil || !finished.Result.Response.Ok {
		t.Fatalf("unexpected logout result: %+v / %v", finished.Result, finished.Err)
	}

	teaModel, _ = teaModel.(Model).Update(finished)
	updated := teaModel.(Model)

	if updated.sessionHint.Authenticated {
		t.Fatalf("expected unauthenticated session hint")
	}

	if updated.status.Level != types.StatusLevelSuccess {
		t.Fatalf("expected success status, got %q", updated.status.Level)
	}
}

func TestLoginFinishedSuccessUpdatesSessionHint(t *testing.T) {
	model := NewModel(types.AppConfig{EnginePath: "engine_cli.exe", DataDir: ".engine-data"}, stubService{})
	model.route = types.RouteLogin

	next, _ := model.Update(messages.LoginFinished{
		LoginID: "alice",
		Result: engineclient.CommandResult[engineclient.EmptyData]{
			Response: engineclient.Response[engineclient.EmptyData]{
				Ok:     true,
				Result: "success",
				Data:   &engineclient.EmptyData{},
			},
		},
	})

	updated := next.(Model)
	if !updated.sessionHint.Authenticated || updated.sessionHint.LoginID != "alice" {
		t.Fatalf("unexpected session hint: %+v", updated.sessionHint)
	}

	if updated.route != types.RouteHome {
		t.Fatalf("expected route %q, got %q", types.RouteHome, updated.route)
	}
}

func TestQInRegisterFormDoesNotQuitAndUpdatesInput(t *testing.T) {
	model := NewModel(types.AppConfig{EnginePath: "engine_cli.exe", DataDir: ".engine-data"}, stubService{})
	model.route = types.RouteRegister

	next, command := model.Update(tea.KeyMsg{Type: tea.KeyRunes, Runes: []rune("q")})
	if command != nil {
		t.Fatalf("expected no quit command while editing register form")
	}

	updated := next.(Model)
	loginID, _ := updated.registerScreen.Values()
	if loginID != "q" {
		t.Fatalf("expected register login id to accept typed q, got %q", loginID)
	}
}
