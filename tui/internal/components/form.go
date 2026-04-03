package components

import (
	"strings"

	tea "github.com/charmbracelet/bubbletea"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * InputSpec defines one text input used by a form.
 */
type InputSpec struct {
	Label       string
	Placeholder string
	Password    bool
}

type formField struct {
	label       string
	placeholder string
	password    bool
	value       []rune
	cursor      int
}

/**
 * Form manages a compact multi-field text form.
 */
type Form struct {
	theme       style.Theme
	fields      []formField
	focusIndex  int
	submitLabel string
	width       int
}

/**
 * NewForm creates one form from the provided field specifications.
 */
func NewForm(specs []InputSpec, submitLabel string, theme style.Theme) Form {
	form := Form{
		theme:       theme,
		fields:      make([]formField, len(specs)),
		submitLabel: submitLabel,
		width:       32,
	}

	for index, spec := range specs {
		form.fields[index] = formField{
			label:       spec.Label,
			placeholder: spec.Placeholder,
			password:    spec.Password,
		}
	}

	return form
}

/**
 * Update advances focus and edits the active field in response to key events.
 */
func (f *Form) Update(msg tea.Msg) tea.Cmd {
	keyMsg, ok := msg.(tea.KeyMsg)
	if !ok || len(f.fields) == 0 {
		return nil
	}

	switch keyMsg.String() {
	case "tab", "down":
		f.focusIndex = (f.focusIndex + 1) % len(f.fields)
		return nil
	case "shift+tab", "up":
		f.focusIndex = (f.focusIndex - 1 + len(f.fields)) % len(f.fields)
		return nil
	}

	field := &f.fields[f.focusIndex]
	switch keyMsg.Type {
	case tea.KeyLeft:
		if field.cursor > 0 {
			field.cursor--
		}
	case tea.KeyRight:
		if field.cursor < len(field.value) {
			field.cursor++
		}
	case tea.KeyBackspace:
		if field.cursor > 0 {
			field.value = append(field.value[:field.cursor-1], field.value[field.cursor:]...)
			field.cursor--
		}
	case tea.KeyDelete:
		if field.cursor < len(field.value) {
			field.value = append(field.value[:field.cursor], field.value[field.cursor+1:]...)
		}
	case tea.KeyHome:
		field.cursor = 0
	case tea.KeyEnd:
		field.cursor = len(field.value)
	case tea.KeyRunes:
		field.value = append(field.value[:field.cursor], append(keyMsg.Runes, field.value[field.cursor:]...)...)
		field.cursor += len(keyMsg.Runes)
	}

	return nil
}

/**
 * Reset clears all field values and moves focus back to the first field.
 */
func (f *Form) Reset() {
	for index := range f.fields {
		f.fields[index].value = f.fields[index].value[:0]
		f.fields[index].cursor = 0
	}

	f.focusIndex = 0
}

/**
 * SetWidth updates the visible width used when rendering each input field.
 */
func (f *Form) SetWidth(width int) {
	if width > 0 {
		f.width = width
	}
}

/**
 * Value returns one field value by index.
 */
func (f Form) Value(index int) string {
	if index < 0 || index >= len(f.fields) {
		return ""
	}

	return string(f.fields[index].value)
}

/**
 * View renders the complete form body.
 */
func (f Form) View() string {
	lines := make([]string, 0, len(f.fields)*3+1)
	for index, field := range f.fields {
		lines = append(lines, f.theme.Subtitle(field.label))
		inputView := renderField(field, index == f.focusIndex)
		if index == f.focusIndex {
			lines = append(lines, f.theme.FocusedInputStyle().Width(f.width).Render(inputView))
		} else {
			lines = append(lines, f.theme.BlurredInputStyle().Width(f.width).Render(inputView))
		}
		lines = append(lines, "")
	}

	helpText := "Enter to " + f.submitLabel + " | Tab to move focus | Esc to return"
	lines = append(lines, f.theme.Muted(helpText))
	return strings.Join(lines, "\n")
}

func renderField(field formField, focused bool) string {
	value := string(field.value)
	if field.password {
		value = strings.Repeat("*", len(field.value))
	}

	if value == "" {
		value = field.placeholder
	}

	if !focused {
		return value
	}

	cursor := field.cursor
	if cursor < 0 {
		cursor = 0
	}

	runes := []rune(value)
	if cursor > len(runes) {
		cursor = len(runes)
	}

	if cursor == len(runes) {
		return string(runes) + "_"
	}

	return string(runes[:cursor]) + "_" + string(runes[cursor:])
}
