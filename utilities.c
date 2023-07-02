#include "sudoku.h"

void	print_board(t_grid* grid)
{
	int i = 0;

	while (i < 81)
	{
		if (i % 27 == 0)
			printf("------------------------\n");
		if (i % 3 == 0)
			printf("| ");
		printf("%d ", grid->board[i].value);
			i++;
		if (i % 9 == 0)
			printf("|\n");
	}
	printf("------------------------\n");
}
