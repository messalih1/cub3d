#ifndef MAP_H
#define MAP_H

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

typedef struct s_cub_info{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	**map;
	int		f_int;
	int		c_int;
	int		player_x;
	int		player_y;
}   t_cub_info;

void 	name_checker(char *path_name);
int 	content_checker(char *path_name, t_cub_info *cub_info);
int 	map_error(char *error_message, int  error_value, t_cub_info *cub_info);
int 	double_pointer_len(char **pointer);
void	texture_generator(t_cub_info  *cub_info, int	fd);
void    freee(char  **pointer);
void    cub_info_struct_free(t_cub_info *cub_info);
void	get_map(char	*line, int	fd, t_cub_info *cub_info);
void    check_texture_files(t_cub_info  *cub_info);
void	rgb_check(t_cub_info	*cub_info);
int		skip_front_space(char	*line);
int		skip_back_space(char	*line);

#endif