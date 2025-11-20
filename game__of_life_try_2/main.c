#include"game_of_life.h"
void ft_free_mat(char **mat)
{
	if (!mat)
	{
		return;
	}
	for (size_t i = 0; mat[i]; i++)
	{
		free(mat[i]);
	}
	free(mat);
	
	
}
int main(int argc,char **argv)
{
	if (argc != 4)
	{
		return 1;
	}
	struct game_of_life *board = init_struct(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
	read_input(board);
	char **res = NULL;
	while (board->iter >= 0)
	{
		res = simulation(board);
		board->map = copy_mat(res);
		board->iter--;
	}
	print_mat(board->map);
	return(0);
}