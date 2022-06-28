#include "slide_line.h"

/**
 * slide_line - Slides and merges horizontally an array of integers,
 *              2048 style.
 * @line: An array of integers to be merged.
 * @size: The size of line.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 *
 * Return: 1 if successful slide. 0 otherwise.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t current, next, end, step, empty;

	if (!(line && (direction == SLIDE_LEFT || direction == SLIDE_RIGHT)))
		return (0);
	if (size == 1)
		return (1);
	if (direction == SLIDE_LEFT)
		current = empty = 0, end = size, step = 1;
	else
		current = empty = size - 1, end = -1, step = -1;
	for (next = current + step; current != end; current += step)
	{
		if (line[current] == 0)
			continue;
		for (next = current + step; next != end; next += step)
		{
			if (line[next] == 0)
				continue;
			if (line[current] != line[next])
				break;
			line[empty] = line[current] + line[next];
			if (current != empty)
				line[current] = 0;
			line[next] = 0;
		}
		if (current != empty && line[empty] == 0)
		{
			line[empty] = line[current];
			line[current] = 0;
		}
		empty += step;
	}
	return (1);
}
