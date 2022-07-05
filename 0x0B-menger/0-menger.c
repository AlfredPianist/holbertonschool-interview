#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge.
 * @level: The level of the Menger Sponge to print.
 */
void menger(int level)
{
	int row, column, inner, size;
	char symbol;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			symbol = '#';
			for (inner = 1; inner < size; inner *= 3)
				if ((row / inner) % 3 == 1 && (column / inner) % 3 == 1)
				{
					symbol = ' ';
					break;
				}
			putchar(symbol);
		}
		putchar('\n');
	}
}
