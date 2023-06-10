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

int***	update_row(int*** grid, int x);
int***	update_column(int*** grid, int y);
int***	update_box(int*** grid, int boxnum);

bool	number_solved(int* num);
void	box_cells(int boxnum, int* x, int* y);
int*	copy_cell(int* dest, int* src);

/* Utilities */

void	print_board(int*** grid);
void	print_cell(int* cell);
void	print_row(int** row);

/* Methods */

int***	check_board(int*** grid);


#endif