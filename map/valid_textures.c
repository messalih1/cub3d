/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:25:51 by tnamir            #+#    #+#             */
/*   Updated: 2022/09/03 12:56:18 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	textures_nl_remover(t_cub_info  *cub_info)
{
	if (cub_info->EA[ft_strlen(cub_info->EA) - 1] == '\n')
		cub_info->EA[ft_strlen(cub_info->EA) - 1] = '\0';
	if (cub_info->WE[ft_strlen(cub_info->WE) - 1] == '\n')
		cub_info->WE[ft_strlen(cub_info->WE) - 1] = '\0';
	if (cub_info->NO[ft_strlen(cub_info->NO) - 1] == '\n')
		cub_info->NO[ft_strlen(cub_info->NO) - 1] = '\0';
	if (cub_info->SO[ft_strlen(cub_info->SO) - 1] == '\n')
		cub_info->SO[ft_strlen(cub_info->SO) - 1] = '\0';
	if (cub_info->F[ft_strlen(cub_info->F) - 1] == '\n')
		cub_info->F[ft_strlen(cub_info->F) - 1] = '\0';
	if (cub_info->C[ft_strlen(cub_info->C) - 1] == '\n')
		cub_info->C[ft_strlen(cub_info->C) - 1] = '\0';
}

void    check_texture_files(t_cub_info  *cub_info)
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;

	textures_nl_remover(cub_info);
	fd1 = open(cub_info->EA, O_RDONLY);
	fd2 = open(cub_info->WE, O_RDONLY);
	fd3 = open(cub_info->NO, O_RDONLY);
	fd4 = open(cub_info->SO, O_RDONLY);
	if (fd1 == -1 || fd2== -1 || fd3 == -1 || fd4 == -1)
		map_error("invalid texture files", EXIT_FAILURE, cub_info);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

void	coma_count_fct(t_cub_info	*cub_info)
{
	int	coma_count;
	int x;

	coma_count = 0;
	x = -1;
	while (cub_info->C[++x])
		if (cub_info->C[x] == ',')
			coma_count++;
	x = -1;
	while (cub_info->F[++x])
		if (cub_info->F[x] == ',')
			coma_count++;
	if (coma_count != 4)
		map_error("invalid rgb configuration", EXIT_FAILURE, cub_info);
}

void	valid_rgb(char	**c, char	**f, t_cub_info *cub_info)
{
	int		x;
	int		y;

	x = 0;
	while (c[x] && f[x])
	{
		y = -1;
		while (c[x][++y])
			if (!ft_isdigit(c[x][y]))
				map_error("invalid rgb configuration in C", EXIT_FAILURE, cub_info);
		if (ft_atoi(c[x]) < 0 || ft_atoi(c[x]) > 255)
			map_error("invalid rgb configuration in C", EXIT_FAILURE, cub_info);
		y = -1;
		while (f[x][++y])
			if (!ft_isdigit(f[x][y]))
				map_error("invalid rgb configuration in F", EXIT_FAILURE, cub_info);
		if (ft_atoi(f[x]) < 0 || ft_atoi(f[x]) > 255)
			map_error("invalid rgb configuration in F", EXIT_FAILURE, cub_info);
		x++;
	}
}

void	rgb_check(t_cub_info	*cub_info)
{
	char	**c;
	char	**f;

	coma_count_fct(cub_info);
	c = ft_split(cub_info->C, ',');
	f = ft_split(cub_info->F, ',');
	valid_rgb(c, f, cub_info);
	cub_info->c_int = (ft_atoi(c[0]) << 16) + (ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	cub_info->c_int = (ft_atoi(c[0]) << 16) + (ft_atoi(c[1]) << 8) + ft_atoi(c[2]);
	freee(c);
	freee(f);
	return ;
}