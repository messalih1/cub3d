#include "../includes/header.h"


void	my_mlx_pixel_put(t_player *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_floor_roof(t_player *p)
{
    int y;

    p->wall.floor_px = (int)(p->win_height / 2 + p->wall.wall_strip_height / 2);
    y = p->wall.floor_px;
    while (y < p->win_height)
    {
        my_mlx_pixel_put(p, p->wall.x , y, p->cub_info.f_int);
        y++;
    }
    p->wall.roof_px = (int)(p->win_height / 2 - p->wall.wall_strip_height / 2);
    y = 0;
    while (y < p->wall.roof_px)
    { 
        my_mlx_pixel_put(p, p->wall.x , y, p->cub_info.c_int);
        y++;
    }

}

void free_all(t_player *p, t_tx   *texture)
{
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.mlx_win, p->mlx.img, 0, 0);
    free(p->distance);
	free(p->ver.distance);
	free(p->hor.distance);
	free(p->px);
	free(p->py);
	free(p->if_is_vertical);
	free(p->angle_ray);
	free(texture);
}