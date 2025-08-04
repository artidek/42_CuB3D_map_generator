#ifndef MAP_GEN_H
# define MAP_GEN_H

# include "get_next_line/get_next_line.h"
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	free_arr(char **arr);
void	free_grid(int **grid, int height);
int		arr_len(char **arr);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		**init_grid(char *map, int *height, int *width);

#endif