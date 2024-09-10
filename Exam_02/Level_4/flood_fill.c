#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	flood_fill_aux(char **tab, t_point size, t_point begin, char sub)
{
	if (begin.x >= size.x || begin.y >= size.y || begin.y < 0 || begin.x < 0 || tab[begin.y][begin.x] != sub)
		return;
	tab[begin.y][begin.x] = 'F';
	flood_fill_aux(tab, size, (t_point) {begin.x + 1, begin.y}, sub);
	flood_fill_aux(tab, size, (t_point) {begin.x - 1, begin.y}, sub);
	flood_fill_aux(tab, size, (t_point) {begin.x, begin.y + 1}, sub);
	flood_fill_aux(tab, size, (t_point) {begin.x, begin.y - 1}, sub);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
	flood_fill_aux(tab, size, begin, tab[begin.y][begin.x]);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

void	print_matrix(char **matrix, int x, int y)
{
	for(int i =0; i < x; i++)
	{
		printf("%s\n", matrix[i]);
	}
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}