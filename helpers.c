#include "map_gen.h"

void	free_arr(char **arr)
{
	int	i = 0;

	while(arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_grid(int **grid, int height)
{
	for (int i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

int	**init_grid(char *map, int *height, int *width)
{
	int fd = open(map, O_RDWR);
	int	**grid;
	char *line = NULL;
	char **h_w;

	if (fd < 0)
		return NULL;
	for (int i = 0; i < 3; i++)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	h_w = ft_split(line, ' ');
	free(line);
	line = get_next_line(fd);
	free(line);
	*height = atoi(h_w[0]);
	*width = atoi(h_w[1]);
	free_arr(h_w);
	grid = malloc(sizeof(int *) * (*height));
	for (int i = 0; i < (*height); i++)
	{
		grid[i] = malloc(sizeof(int) * ((*width) * 3));
		for (int j = 0; j < (*width) * 3; j += 3)
		{
			line = get_next_line(fd);
			grid[i][j] = atoi(line);
			free(line);
			line = get_next_line(fd);
			grid[i][j + 1] = atoi(line);
			free(line);
			line = get_next_line(fd);
			grid[i][j + 2] = atoi(line);
			free(line);
		}
	}
	close(fd);
	return grid;
}