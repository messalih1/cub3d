#include "map.h"

int map_error(char *error_message, int  error_value, t_cub_info *cub_info)
{
	if (error_message)
	{
		write(2, "cub3D: ", 7);
		write(2, error_message, ft_strlen(error_message));
	}
	if (cub_info->NO)
		free(cub_info->NO);
	if (cub_info->SO)
    	free(cub_info->SO);
	if (cub_info->EA)
    	free(cub_info->EA);
    if (cub_info->WE)
		free(cub_info->WE);
    if (cub_info->F)
		free(cub_info->F);
    if (cub_info->C)
		free(cub_info->C);
	if (cub_info->map)
		freee(cub_info->map);
	exit(error_value);
}