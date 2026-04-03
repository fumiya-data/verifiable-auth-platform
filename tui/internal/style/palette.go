package style

import "github.com/charmbracelet/lipgloss"

/**
 * Palette defines the core colors used by the TUI theme.
 */
type Palette struct {
	Background lipgloss.Color
	Surface    lipgloss.Color
	Border     lipgloss.Color
	Accent     lipgloss.Color
	Success    lipgloss.Color
	Warning    lipgloss.Color
	Danger     lipgloss.Color
	Muted      lipgloss.Color
	Text       lipgloss.Color
}

/**
 * DefaultPalette returns the standard TUI color palette.
 */
func DefaultPalette() Palette {
	return Palette{
		Background: lipgloss.Color("#101820"),
		Surface:    lipgloss.Color("#18314F"),
		Border:     lipgloss.Color("#5C6B73"),
		Accent:     lipgloss.Color("#F2AA4C"),
		Success:    lipgloss.Color("#6BBF59"),
		Warning:    lipgloss.Color("#F0A202"),
		Danger:     lipgloss.Color("#D64550"),
		Muted:      lipgloss.Color("#B8C0C8"),
		Text:       lipgloss.Color("#F4F4F0"),
	}
}
