#include "map.h"

void	texture_nuller(t_cub_info  *cub_info)
{
	cub_info->NO = NULL;
	cub_info->SO = NULL;
	cub_info->EA = NULL;
	cub_info->WE = NULL;
	cub_info->F = NULL;
	cub_info->C = NULL;
	cub_info->map = NULL;
}

void	texture_assigner(t_cub_info  *cub_info, char	**texture)
{
	if (!ft_strncmp(texture[0], "NO", 3))
		cub_info->NO = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "SO", 3))
		cub_info->SO = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "EA", 3))
		cub_info->EA = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "WE", 3))
		cub_info->WE = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "F", 2))
		cub_info->F = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "C", 2))
		cub_info->C = ft_strdup(texture[1]);
	else
		map_error("invalid element in file", EXIT_FAILURE, cub_info);
	if (texture[2] && ft_strncmp(texture[2], "\n", 2))
		map_error("invalid element in file", EXIT_FAILURE, cub_info);
}

char	*texture_assigner_caller(char	*line, t_cub_info  *cub_info, int	fd)
{
	char	**texture;

	while (line)
	{
		while (line && (!ft_strncmp("\r\n", line, 3) || !ft_strncmp("\n", line, 2)))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (line)
		{
			texture = ft_split(line, ' ');
			if ((ft_strncmp(texture[0], "NO", 3) && ft_strncmp(texture[0], "WE", 3) && ft_strncmp(texture[0], "SO", 3)
				&& ft_strncmp(texture[0], "EA", 3) && ft_strncmp(texture[0], "F", 2) && ft_strncmp(texture[0], "C", 2))
				|| (cub_info->C && cub_info->F && cub_info->EA && cub_info->NO && cub_info->WE && cub_info->SO))
			{
				freee(texture);
				break ;
			}
			texture_assigner(cub_info, texture);
			freee(texture);
			free(line);
			line = get_next_line(fd);
		}
	}
	return (line);
}

void	texture_generator(t_cub_info  *cub_info, int	fd)
{
	char	*line;

	line = get_next_line(fd);
	texture_nuller(cub_info);
	line = texture_assigner_caller(line, cub_info, fd);
	if (!cub_info->C || !cub_info->F || !cub_info->NO
		|| !cub_info->WE || !cub_info->SO || !cub_info->EA)
		map_error("a texture element is missing", EXIT_FAILURE, cub_info);
	check_texture_files(cub_info);
	rgb_check(cub_info);
	/// leaks free FOR NOW /     -/|\-    / that's a road u dumbass
	///                         -/ | \-    /////////
	///                        -/  |  \-   /////////
	///                       -/   |   \-   /////////
	get_map(line, fd, cub_info);
}