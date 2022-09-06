#include "map.h"

void    freee(char  **pointer)
{
	int i;

	if (pointer)
	{
		i = -1;
		while (pointer[++i])
			free(pointer[i]);
	}
	free(pointer);
}

void    cub_info_struct_free(t_cub_info *cub_info)
{
	free(cub_info->NO);
	free(cub_info->SO);
	free(cub_info->EA);
	free(cub_info->WE);
	free(cub_info->F);
	free(cub_info->C);
	freee(cub_info->map);
}

int double_pointer_len(char **pointer)
{
    int x;

    x = 0;
    while (pointer[x])
        x++;
    return (x);
}

int	skip_front_space(char	*line)
{
	int	x;

	x = 0;
	while (line[x] == ' ')
		x++;
	return (x);
}

int	skip_back_space(char	*line)
{
	int	x;

	x = ft_strlen(line);
	while(line[x - 1] == ' ')
		x--;
	return (x);
}