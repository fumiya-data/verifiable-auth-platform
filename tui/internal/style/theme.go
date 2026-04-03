package style

import (
	"github.com/charmbracelet/lipgloss"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/types"
)

/**
 * Theme provides reusable styles for the TUI.
 */
type Theme struct {
	palette Palette
}

/**
 * DefaultTheme returns the standard application theme.
 */
func DefaultTheme() Theme {
	return Theme{palette: DefaultPalette()}
}

/**
 * Shell wraps the active screen in the outer application frame.
 */
func (t Theme) Shell(content string) string {
	return lipgloss.NewStyle().
		Background(t.palette.Background).
		Foreground(t.palette.Text).
		Padding(1, 2).
		Render(content)
}

/**
 * Panel wraps content in the standard bordered panel style.
 */
func (t Theme) Panel(content string) string {
	return lipgloss.NewStyle().
		Border(lipgloss.NormalBorder()).
		BorderForeground(t.palette.Border).
		Padding(1, 2).
		Render(content)
}

/**
 * Title renders a primary heading.
 */
func (t Theme) Title(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Accent).
		Bold(true).
		Render(content)
}

/**
 * Subtitle renders secondary text.
 */
func (t Theme) Subtitle(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Muted).
		Render(content)
}

/**
 * Accent renders accent-colored content.
 */
func (t Theme) Accent(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Accent).
		Render(content)
}

/**
 * Success renders success-colored content.
 */
func (t Theme) Success(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Success).
		Bold(true).
		Render(content)
}

/**
 * Warning renders warning-colored content.
 */
func (t Theme) Warning(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Warning).
		Render(content)
}

/**
 * Error renders error-colored content.
 */
func (t Theme) Error(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Danger).
		Bold(true).
		Render(content)
}

/**
 * Muted renders low-emphasis content.
 */
func (t Theme) Muted(content string) string {
	return lipgloss.NewStyle().
		Foreground(t.palette.Muted).
		Render(content)
}

/**
 * FocusedInputStyle returns the style for the active input field.
 */
func (t Theme) FocusedInputStyle() lipgloss.Style {
	return lipgloss.NewStyle().
		Foreground(t.palette.Text).
		Border(lipgloss.RoundedBorder()).
		BorderForeground(t.palette.Accent).
		Padding(0, 1)
}

/**
 * BlurredInputStyle returns the style for inactive input fields.
 */
func (t Theme) BlurredInputStyle() lipgloss.Style {
	return lipgloss.NewStyle().
		Foreground(t.palette.Text).
		Border(lipgloss.NormalBorder()).
		BorderForeground(t.palette.Border).
		Padding(0, 1)
}

/**
 * MenuItemStyle returns the style for a home-menu item.
 */
func (t Theme) MenuItemStyle(selected bool) lipgloss.Style {
	if selected {
		return lipgloss.NewStyle().
			Foreground(t.palette.Background).
			Background(t.palette.Accent).
			Bold(true).
			Padding(0, 1)
	}

	return lipgloss.NewStyle().
		Foreground(t.palette.Text).
		Padding(0, 1)
}

/**
 * TableHeaderStyle returns the style for audit table headers.
 */
func (t Theme) TableHeaderStyle() lipgloss.Style {
	return lipgloss.NewStyle().
		Foreground(t.palette.Background).
		Background(t.palette.Accent).
		Bold(true).
		Padding(0, 1)
}

/**
 * TableCellStyle returns the style for audit table cells.
 */
func (t Theme) TableCellStyle() lipgloss.Style {
	return lipgloss.NewStyle().
		Foreground(t.palette.Text).
		Padding(0, 1)
}

/**
 * TableSelectedStyle returns the style for the selected audit row.
 */
func (t Theme) TableSelectedStyle() lipgloss.Style {
	return lipgloss.NewStyle().
		Foreground(t.palette.Background).
		Background(t.palette.Success).
		Bold(true)
}

/**
 * StatusStyle returns the style for one status level.
 */
func (t Theme) StatusStyle(level types.StatusLevel) lipgloss.Style {
	switch level {
	case types.StatusLevelSuccess:
		return lipgloss.NewStyle().Foreground(t.palette.Success)
	case types.StatusLevelWarning:
		return lipgloss.NewStyle().Foreground(t.palette.Warning)
	case types.StatusLevelError:
		return lipgloss.NewStyle().Foreground(t.palette.Danger).Bold(true)
	default:
		return lipgloss.NewStyle().Foreground(t.palette.Muted)
	}
}

/**
 * Modal wraps modal content in the standard overlay style.
 */
func (t Theme) Modal(content string) string {
	return lipgloss.NewStyle().
		Border(lipgloss.DoubleBorder()).
		BorderForeground(t.palette.Accent).
		Padding(1, 2).
		Render(content)
}
