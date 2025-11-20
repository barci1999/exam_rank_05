# pragma once
# include<unistd.h>
# include<stdbool.h>
# include<stdlib.h>
# include<stdio.h>
struct game_of_life
{
	int colum;
	int fila;
	int height;
	int widht;
	bool draawing;
	char  **map;
	int iter;
};
struct game_of_life* init_struct(int width,int height,int iter);
void read_input(struct game_of_life *board);
char **simulation(struct game_of_life *board);
int ft_strlen(char *str);
char *ft_strdup(char *str);
char **copy_mat(char **mat);
void print_mat(char **mat);
