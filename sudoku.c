#include "sudoku.h"

static bool	solve_puzzle(t_grid* grid)
{
	int pos = 0; static unsigned long long iter = 0;

	iter++;
	while (pos < 81)
	{
		if (grid->board[pos].solved == false)
		{
			for (int try = 1; try <= 9; try++)
			{
				if (check_if_possible(grid->board, pos, try) == true)
				{
					grid->board[pos].value = try;
					grid->board[pos].solved = true;
					if (solve_puzzle(grid) == true)
						return (true);
				}
				grid->board[pos].value = 0;
				grid->board[pos].solved = false;
			}
			return (false);
		}
		pos++;
	}
	return (printf("Recursive iterations: %llu\n", iter), true);
}

static void	pre_solve(t_grid* grid)
{
	int i = 0; int check = 0;

	while (i < 81)
	{
		while (i < 81 && grid->board[i].solved == true)
			i++;
		if (i < 81 && single_possibility(grid->board, i) == true)
		{
			check = 1;
			i++;
		}
		i++;
	}
	if (check == 1)
		pre_solve(grid);
}

static void	parse_input(t_grid* grid, char** argv)
{
	int i = 0;

	while (argv[i + 1])
	{
		if (strlen(argv[i + 1]) != 1 || (!isdigit(*argv[i + 1])))
		{
			puts("Invalid input");
			exit(EXIT_FAILURE);
		}
		grid->board[i].value = atoi(argv[i + 1]);
		if (grid->board[i].value == 0)
			grid->board[i].solved = false;
		else
			grid->board[i].solved = true;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_grid	grid;
	clock_t start_time; clock_t end_time;

	printf("Argc: %d\n", argc);
	if (argc != 82)
		return (1);
	parse_input(&grid, argv);
	printf("Initial board:\n\n");
	print_board(&grid);
	start_time = clock();
	pre_solve(&grid);
	if (solve_puzzle(&grid) == true)
	{
		printf("\nSolved!\nFinal board:\n\n");
		print_board(&grid);
	}
	else
	{
		printf("Couldn't solve :-(\n");
		print_board(&grid);
	}
	end_time = clock();
	printf("Running time (seconds): %.2f\n", (float)end_time - start_time / CLOCKS_PER_SEC);
}