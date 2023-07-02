#ifndef SUDOKU_H
#define SUDOKU_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

typedef struct s_cell
{
	uint8_t	value;
	bool	solved;
}	t_cell;

typedef struct s_grid
{
	t_cell	board[81];
}	t_grid;

/* Utilities */

void	print_board(t_grid* grid);

/* Methods */

/* Vision */

bool	check_if_possible(t_cell* board, uint8_t pos, uint8_t try);
bool	single_possibility(t_cell* board, uint8_t pos);

#endif