#include "sudoku.h"

void	box_cells(int boxnum, int* x, int* y)
{
	if (boxnum == 0)
	{
		*x = 0;
		*y = 0;
	}
	if (boxnum == 1)
	{
		*x = 0;
		*y = 3;
	}
	if (boxnum == 2)
	{
		*x = 0;
		*y = 6;	
	}
	if (boxnum == 3)
	{
		*x = 3;
		*y = 0;
	}
	if (boxnum == 4)
	{
		*x = 3;
		*y = 3;
	}
	if (boxnum == 5)
	{
		*x = 3;
		*y = 6;
	}
	if (boxnum == 6)
	{
		*x = 6;
		*y = 0;
	}
	if (boxnum == 7)
	{
		*x = 6;
		*y = 3;
	}
	if (boxnum == 8)
	{
		*x = 6;
		*y = 6;
	}
}

int*	copy_cell(int* dest, int* src)
{
	int i = 0;

	while (i < 10)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

bool	number_solved(int* num)
{
	int i = 1; int x = 0;

	if (num[0] == 1)
		return (true);
	while (i < 10)
	{
		if (num[i] != 0)
			x++;
		if (x == 2)
			return (false);
		i++;
	}
	return (true);
}

void	print_board(int*** grid)
{
	int x = 0;
	int y;

	while (x < 9)
	{
		if (x % 3 == 0)
			printf("------------------------\n");
		y = 0;
		while (y < 9)
		{
			if (y % 3 == 0)
				printf("| ");
			if (grid[x][y][0] == 0)
				printf("0 ");
			else
				printf("%d ", grid[x][y][1]);
			y++;
		}
		printf("|\n");
		x++;
	}
	printf("------------------------\n");
}

void	print_cell(int* cell)
{
	for (int i = 0; i < 10; i++)
		printf("%d,", cell[i]);
	printf("\n");
}

void	print_row(int** row)
{
	int i = 0;
	while (i < 9)
	{
		print_cell(row[i]);
		i++;
		printf("--------------------\n");
	}
}