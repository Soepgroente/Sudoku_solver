#include "sudoku.h"

int*	update_cell(int* cell, int* rmv)
{
	int i = 1;

	if (cell[0] == 1)
		return (cell);
	while (i < 10)
	{
		for (int q = 0; q < 9; q++)
			if (cell[i] == rmv[q])
				cell[i] = 0;
		i++;
	}
	return (cell);
}

int*	solve_cell(int* cell)
{
	int i = 0;

	if (cell[0] == 1)
		return (cell);
	else
		cell[0] = 1;
	while (i < 9)
	{
		i++;
		if (cell[i] != 0)
		{
			cell[1] = i;
			if (i != 1)
				cell[i] = 0;
		}
	}
	return (cell);
}

int***	update_row(int*** grid, int x)
{
	int i = 0; int y = 0;
	int* tmp;
	
	tmp = calloc(10, sizeof(int));
	while (y < 9)
	{
		if (number_solved(grid[x][y]) == true)
		{
			grid[x][y] = solve_cell(grid[x][y]);
			tmp[i] = grid[x][y][1];
			i++;
		}
		y++;
	}
	y = 0;
	while (y < 9)
	{
		grid[x][y] = update_cell(grid[x][y], tmp);
		y++;
	}
	free(tmp);
	return (grid);
}

int***	update_column(int*** grid, int y)
{
	int i = 0; int x = 0;
	int* tmp;

	tmp = calloc(10, sizeof(int));
	while (x < 9)
	{
		if (number_solved(grid[x][y]) == true)
		{
			grid[x][y] = solve_cell(grid[x][y]);
			tmp[i] = grid[x][y][1];
			i++;
		}
		x++;
	}
	x = 0;
	while (x < 9)
	{
		update_cell(grid[x][y], tmp);
		x++;
	}
	free(tmp);
	return (grid);
}

int***	update_box(int*** grid, int boxnum)
{
	int i; int x; int y; int z = 0; int y2;

	box_cells(boxnum, &x, &y);
	i = boxnum + 9;
	y2 = y + 3;
	while (z < 9)
	{
		grid[i][z] = copy_cell(grid[i][z], grid[x][y]);
		z++;
		y++;
		if (y == y2)
		{
			y -= 3;
			x++;
		}
	}
	box_cells(boxnum, &x, &y);
	grid = update_row(grid, i);
	z = 0;
	while (z < 9)
	{
		grid[x][y] = copy_cell(grid[x][y], grid[i][z]);
		z++;
		y++;
		if (y == y2)
		{
			y -= 3;
			x++;
		}
	}
	return (grid);
}
