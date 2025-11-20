#include "game_of_life.h"
struct game_of_life* init_struct(int widht,int height,int iter)
{
	if (widht < 0 || height < 0 || iter < 0)
	{
		return NULL;
	}
	struct game_of_life* board = malloc(sizeof(struct game_of_life));
	if (!board)
	{
		return NULL;
	}
	board->draawing = false;
	board->widht = widht;
	board->height = height;
	board->iter = iter;
	board->colum = 0;
	board->fila = 0;
	board->map = malloc((height + 1) * sizeof(char *));
	if (!board->map)
	{
		free(board);
		return NULL;
	}
	size_t i = 0;
	for (; i < height; i++)
	{
		board->map[i] = malloc((widht +1) + sizeof(char));
		if (!board->map[i])
		{
			for (size_t k = 0; k < i; k++)
			{
				free(board->map[k]);
			}
			free(board->map);
			free(board);
			return(NULL);
		}
		else
		{
			for (size_t j = 0; j < widht; j++)
			{
				board->map[i][j] = ' '; 
			}
			board->map[i][widht] = '\0';
		}
	}
	board->map[i] = NULL;
	return board; 
}

int ft_strlen(char *str)
{
	if (!str)
	{
		return 0;
	}
	int i = 0;
	for (;str[i]; i++)
	{}
	return i;
	
}
void read_input(struct game_of_life *board)
{
	char c;
	while (read(0,&c,1) > 0)
	{
		if (c == 'x')
		{
			board->draawing = !board->draawing;
			if (board->draawing)
			{
				board->map[board->fila][board->colum] = '0';
			}
		}
		if(c == 'w' && board->fila > 0)
		{ 
			board->fila--; 
		}
		else if(c == 's' && board->fila < board->height)
		{
			board->fila++;
		}
		else if(c == 'd' && board->colum < board->widht)
		{
			board->colum++;
		}
		else if(c == 'a' && board->colum > 0 )
		{
			board->colum--;
		}
		if(board->draawing)
		{
			board->map[board->fila][board->colum] = '0';
		}
	}
}
char *ft_strdup(char *str)
{
	size_t len = (size_t)ft_strlen(str);
	char *result = malloc((len +1) *sizeof(char));
	for (size_t i = 0; str[i]; i++)
	{
		result[i] = str[i];
	}
	result[len] = '\0';
	return result;
}
char **copy_mat(char **mat)
{
	size_t mat_len = 0;
	for(;mat[mat_len]; mat_len++)
	{}
	char **result = malloc((mat_len * 1) *sizeof(char *));
	if (!result)
	{
		return NULL;
	}
	size_t i = 0;
	for(; mat[i] ; i++)
	{
		result[i] = ft_strdup(mat[i]);
		if (!result[i])
		{
			while (i >= 0)
			{
				free(result[i]);
			}
			free(result);
			return NULL;
		}
	}
	result[i] = NULL;
	return result;
	
}
void print_mat(char **mat)
{
	if (!mat)
	{
		return;
	}
	for(size_t i = 0 ; mat[i] ; i++)
	{
		for (size_t j = 0; mat[i][j]; j++)
		{
			write(1,&mat[i][j],1);
		}
		write(1,"\n",1);
	}
	
}
char **simulation(struct game_of_life *board)
{
	char **result = copy_mat(board->map);
	if (board->iter <= 0)
	{
		return result;
	}
	size_t i = 0;
	for (; board->map[i]; i++)
	{
		if (i ==  0)
		{
			for (size_t j = 0;board->map[j]; j++)
			{
				int neigboars = 0;
				if (j == 0)
				{
					if(board->map[i][j+1] && board->map[i][j+1] == '0') neigboars++;
					
					if(board->map[i+1][j] && board->map[i+1][j] == '0') neigboars++;
					if(board->map[i+1][j+1] && board->map[i+1][j+1] == '0') neigboars++;
				}
				else if (j == ft_strlen(board->map[i]) - 1)
				{
					if(board->map[i][j-1] && board->map[i][j-1] == '0') neigboars++;
					
					if(board->map[i+1][j-1] && board->map[i+1][j-1] == '0') neigboars++;
					if(board->map[i+1][j] && board->map[i+1][j] == '0') neigboars++;
				}
				else
				{
					if(board->map[i][j+1] && board->map[i][j+1] == '0') neigboars++;
					if(board->map[i][j-1] && board->map[i][j-1] == '0') neigboars++;

					if(board->map[i+1][j+1] && board->map[i+1][j+1] == '0') neigboars++;
					if(board->map[i+1][j-1] && board->map[i+1][j-1] == '0') neigboars++;
					if(board->map[i+1][j] && board->map[i+1][j] == '0') neigboars++;
				}
				if (result[i][j] == '0')
				{
					result[i][j] = (neigboars == 3 || neigboars == 2) ? '0':' ';
				}
				else
				{
					result[i][j] = (neigboars == 3) ? '0' : ' ';
				}
			}
			
		}
		else if (i == board->height -1)
		{
			for (size_t j = 0; board->map[i][j]; j++)
			{
				int neigboars = 0;
				if (j == 0)
				{
					if(board->map[i][j+1] && board->map[i][j+1] == '0') neigboars++;
					
					if(board->map[i-1][j+1] && board->map[i-1][j+1] == '0') neigboars++;
					if(board->map[i-1][j] && board->map[i-1][j] == '0') neigboars++;
				}
				else if (j == ft_strlen(board->map[i]) -1)
				{
					if(board->map[i][j-1] && board->map[i][j-1] == '0') neigboars++;
					
					if(board->map[i-1][j-1] && board->map[i-1][j-1] == '0') neigboars++;
					if(board->map[i-1][j] && board->map[i-1][j] == '0') neigboars++;
				}
				else
				{
					if(board->map[i][j-1] && board->map[i][j-1] == '0') neigboars++;
					if(board->map[i][j+1] && board->map[i][j+1] == '0') neigboars++;

					if(board->map[i-1][j-1] && board->map[i-1][j-1] == '0') neigboars++;
					if(board->map[i-1][j] && board->map[i-1][j] == '0') neigboars++;
					if(board->map[i-1][j+1] && board->map[i-1][j+1] == '0') neigboars++;
				}
				if (result[i][j] == '0')
				{
					result[i][j] = (neigboars == 3 || neigboars == 2) ? '0':' ';
				}
				else
				{
					result[i][j] = (neigboars == 3) ? '0' : ' ';
				}
			}
		}
		else
		{
			for (size_t j = 0; board->map[i][j]; j++)
			{
				int neigboars = 0;
				if (j == 0)
				{
					if(board->map[i][j+1] && board->map[i][j+1] == '0') neigboars++;
					
					if(board->map[i+1][j+1] && board->map[i+1][j+1] == '0') neigboars++;
					if(board->map[i+1][j] && board->map[i+1][j] == '0') neigboars++;

					if(board->map[i-1][j+1] && board->map[i-1][j+1] == '0') neigboars++;
					if(board->map[i-1][j] && board->map[i-1][j] == '0') neigboars++;
				}
				else if (j == ft_strlen(board->map[i]) -1)
				{
					if(board->map[i-1][j] && board->map[i-1][j] == '0') neigboars++;
					if(board->map[i-1][j-1] && board->map[i-1][j-1] == '0') neigboars++;

					if(board->map[i][j-1] && board->map[i][j-1] == '0') neigboars++;

					if(board->map[i+1][j-1] && board->map[i+1][j-1] == '0') neigboars++;
					if(board->map[i+1][j] && board->map[i+1][j] == '0') neigboars++;
				}
				else
				{
					if(board->map[i][j+1] && board->map[i][j+1] == '0') neigboars++;
					if(board->map[i][j-1] && board->map[i][j-1] == '0') neigboars++;

					if(board->map[i-1][j-1] && board->map[i-1][j-1] == '0') neigboars++;
					if(board->map[i-1][j+1] && board->map[i-1][j+1] == '0') neigboars++;
					if(board->map[i-1][j] && board->map[i-1][j] == '0') neigboars++;

					if(board->map[i+1][j-1] && board->map[i+1][j-1] == '0') neigboars++;
					if(board->map[i+1][j] && board->map[i+1][j] == '0') neigboars++;
					if(board->map[i+1][j+1] && board->map[i+1][j+1] == '0') neigboars++;
				}
				if (result[i][j] == '0')
				{
					result[i][j] = (neigboars == 3 || neigboars == 2) ? '0':' ';
				}
				else
				{
					result[i][j] = (neigboars == 3) ? '0' : ' ';
				}
			}
		}
	}
	result[i] = NULL;
	return result;
}
