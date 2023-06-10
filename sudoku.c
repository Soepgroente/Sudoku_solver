#include "sudoku.h"

int*** create_board(void)
{
	int*** grid;
	int x = 0;
	int y;

	grid = calloc(18, sizeof(int**));
	while (x < 18)
	{
		y = 0;
		grid[x] = calloc(9, sizeof(int*));
		while (y < 9)
		{
			grid[x][y] = calloc(10, sizeof(int));
			y++;
		}
		x++;
	}
	return (grid);
}

void	parse_input(int*** grid, char** argv)
{
	int i = 1;
	int arg, x = 0, y, z = 0; int y2 = 0; int boxnum = 0;

	while (argv[i] && x < 9)
	{
		y = 0;
		while (y < 9)
		{
			z = 1;
			if (strlen(argv[i]) != 1 || (!isdigit(*argv[i])))
			{
				puts("Invalid input");
				exit(EXIT_FAILURE);
			}
			arg = atoi(argv[i]);
			if (arg == 0)
			{
				while (z < 10)
				{
					grid[x][y][z] = z;
					z++;
				}
			}
			else
			{
				grid[x][y][0] = 1;
				grid[x][y][1] = arg;
			}
			i++;
			y++;
		}
		x++;
	}
	i = 9;
	box_cells(boxnum, &x, &y);
	while (x < 9 && y < 9)
	{
		z = 0;
		y2 = y + 3;
		while (z < 9)
		{
			copy_cell(grid[i][z], grid[x][y]);
			z++;
			y++;
			if (y == y2)
			{
				y -= 3;
				x++;
			}
		}
		boxnum++;
		box_cells(boxnum, &x, &y);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int x = 0;

	if (argc != 82)
		return (1);
	int*** grid = create_board();
	parse_input(grid, argv);
	printf("Initial board:\n");
	print_board(grid);
 	while (x < 100)
	{
		for (int i = 0; i < 9; i++)
			grid = update_row(grid, i);
		for (int q = 0; q < 9; q++)
			grid = update_column(grid, q);
		for (int z = 0; z < 9; z++)
			grid = update_box(grid, z);
		x++;
	}
	printf("Final board:\n");
	print_board(grid);
}