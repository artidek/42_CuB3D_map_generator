#include "map_gen.h"

static void print_map(int **grid, int height, int width, char *name)
{	
	char *line;
	int a;
	char *name_with_ext = ft_strjoin(name, ".cub");
	int fd = open(name_with_ext, O_RDWR | O_CREAT, 0667);
	for (int i = 0; i < height; i++)
	{
		line = malloc(sizeof(char) * width + 1);
		a = 0;
		for (int j = 0; j < width * 3; j += 3)
		{
			if (grid[i][j] == 255 && grid[i][j + 1] == 255 && grid[i][j + 2] == 255)
				line[a] = '1';
			else if (grid[i][j] == 255 && grid[i][j + 1] == 0 && grid[i][j + 2] == 0)
				line[a] = '0';
			else if (grid[i][j] == 0 && grid[i][j + 1] == 0 && grid[i][j + 2] == 255)
				line[a] = ' ';
			a++;
		}
		write(fd, line, width - 1);
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	free(name_with_ext);
}

static void generate_map(char *map)
{
	int height;
	int	width;
	int **grid = init_grid(map,&height,&width);
	char **splited = ft_split(map, '.');
	if (!grid)
		return;
	print_map(grid, height, width, splited[arr_len(splited) - 2]);
	free_arr(splited);
	free_grid(grid, height);
}

static int check_extencion(char *file_name)
{
	char **ext = ft_split(file_name, '.');
	int len = arr_len(ext);
	if (strlen(ext[len - 1]) == 3 && strncmp(ext[len - 1], "ppm", 3) == 0)
	{
		free_arr(ext);
		return (1);
	}
	free_arr(ext);
	return (0);
}

int main ()
{
	char *path = "blueprints";
	DIR *dir = opendir(path);
	struct dirent *entry;

	if (dir == NULL)
	{
		perror("map_gen opendir:");
		return (1);
	}
	while((entry = readdir(dir)) != NULL)
	{
		if (strlen(entry->d_name) > 4)
		{
			if (check_extencion(entry->d_name))
			{
				char *file_path = ft_strjoin("blueprints/", entry->d_name);
				generate_map(file_path);
				free(file_path);
			}
		}
	}
	printf("finished generating maps at ./maps_gen\n");
	closedir(dir);
	return (0);
}