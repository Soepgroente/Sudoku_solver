#include "sudoku.h"

static bool	check_row(t_cell* board, uint8_t pos, uint8_t try)
{
	int i = 0;

	pos -= pos % 9;
	while (i < 9)
	{
		if (board[pos + i].value == try)
			return (false);
		i++;
	}
	return (true);
}

static bool	check_column(t_cell* board, uint8_t pos, uint8_t try)
{
	int i = 0;

	pos = pos % 9;
	while (i < 81)
	{
		if (board[pos + i].value == try)
			return (false);
		i += 9;
	}
	return (true);
}

static bool	check_box(t_cell* board, uint8_t pos, uint8_t try)
{
	int i = 0;
	
	pos -= pos % 3;
	while ((pos - pos % 9) % 27 != 0)
		pos -= 9;
	while (i < 27)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[pos + i + x].value == try)
				return (false);
		}
		i += 9;
	}
	return (true);
}

bool	check_if_possible(t_cell* board, uint8_t pos, uint8_t try)
{
	if (check_row(board, pos, try) == true && \
		check_column(board, pos, try) == true && \
		check_box(board, pos, try) == true)
		return (true);
	else
		return (false);
}

bool	single_possibility(t_cell* board, uint8_t pos)
{
	int count = 0; int value = 0;

	for (int i = 1; i <= 9; i++)
	{
		if (check_if_possible(board, pos, i) == true)
		{
			value = i;
			count++;
		}
	}
	if (count == 1)
	{
		board[pos].value = value;
		return (true);
	}
	else
		return (false);
}