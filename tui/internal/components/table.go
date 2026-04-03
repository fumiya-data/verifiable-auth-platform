package components

import (
	"fmt"
	"strings"

	"github.com/charmbracelet/lipgloss"

	"github.com/fumiya-data/verifiable-auth-platform/tui/internal/style"
)

/**
 * RenderTable renders a compact, fixed-width table.
 */
func RenderTable(theme style.Theme, headers []string, rows [][]string, selected int, width int) string {
	if len(headers) == 0 {
		return theme.Muted("No columns configured.")
	}

	columnWidths := measureColumnWidths(headers, rows, width)
	lines := make([]string, 0, len(rows)+2)
	lines = append(lines, renderHeader(theme, headers, columnWidths))

	if len(rows) == 0 {
		lines = append(lines, theme.Muted("No rows available. Press r to refresh."))
		return strings.Join(lines, "\n")
	}

	for index, row := range rows {
		renderedCells := make([]string, len(headers))
		for cellIndex := range headers {
			cell := ""
			if cellIndex < len(row) {
				cell = truncateCell(row[cellIndex], columnWidths[cellIndex])
			}

			renderedCells[cellIndex] = theme.TableCellStyle().
				Width(columnWidths[cellIndex]).
				Render(cell)
		}

		line := lipgloss.JoinHorizontal(lipgloss.Top, renderedCells...)
		if index == selected {
			line = theme.TableSelectedStyle().Render(line)
		}

		lines = append(lines, line)
	}

	return strings.Join(lines, "\n")
}

func renderHeader(theme style.Theme, headers []string, widths []int) string {
	rendered := make([]string, len(headers))
	for index, header := range headers {
		rendered[index] = theme.TableHeaderStyle().
			Width(widths[index]).
			Render(truncateCell(header, widths[index]))
	}

	return lipgloss.JoinHorizontal(lipgloss.Top, rendered...)
}

func measureColumnWidths(headers []string, rows [][]string, width int) []int {
	widths := make([]int, len(headers))
	for index, header := range headers {
		widths[index] = maxDisplayWidth(header, 8)
	}

	for _, row := range rows {
		for index := range headers {
			if index < len(row) {
				widths[index] = maxDisplayWidth(row[index], widths[index])
			}
		}
	}

	for index := range widths {
		if widths[index] > 28 {
			widths[index] = 28
		}
	}

	if width <= 0 {
		return widths
	}

	totalWidth := 0
	for _, columnWidth := range widths {
		totalWidth += columnWidth
	}

	available := width - 8
	if totalWidth <= available || available <= len(widths)*8 {
		return widths
	}

	for totalWidth > available {
		adjusted := false
		for index := range widths {
			if widths[index] > 8 && totalWidth > available {
				widths[index]--
				totalWidth--
				adjusted = true
			}
		}

		if !adjusted {
			return widths
		}
	}

	return widths
}

func maxDisplayWidth(value string, minimum int) int {
	width := lipgloss.Width(value)
	if width < minimum {
		return minimum
	}

	return width
}

func truncateCell(value string, width int) string {
	if width <= 0 {
		return ""
	}

	if lipgloss.Width(value) <= width {
		return value
	}

	if width <= 3 {
		return value[:width]
	}

	runes := []rune(value)
	limit := width - 3
	if limit > len(runes) {
		limit = len(runes)
	}

	return fmt.Sprintf("%s...", string(runes[:limit]))
}
