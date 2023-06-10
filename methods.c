int***	check_board(int*** grid)
{
	for (int i = 0; i < 9; i++)
		grid = update_row(grid, i);
	for (int q = 0; q < 9; q++)
		grid = update_column(grid, q);
	for (int z = 0; z < 9; z++)
		grid = update_box(grid, z);
	return (grid);
}