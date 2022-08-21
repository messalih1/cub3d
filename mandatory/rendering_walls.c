#include "../includes/header.h"

void	my_mlx_pixel_put(t_player *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void rendering_walls(t_player *p)
{
    int i;
    int x = 0;
    int y;

    
    int s = WINDOW_WIDTH / p->num_of_rays;
    p->img = mlx_new_image(p->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, &p->line_length, &p->endian);
    i = 0;
    
    while (x < WINDOW_WIDTH)
    {
         
        float distance_project_plane = (WINDOW_WIDTH / 2) / tan(p->fov_angle / 2);
        float wall_strip_height = (TILE_SIZE / p->distance[i]) * distance_project_plane;
        if (x % s == 0  && x != 0)
            i++;
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
            if (y >= (int)(WINDOW_HEIGHT / 2 - wall_strip_height / 2) && y <= (int)(WINDOW_HEIGHT / 2 + wall_strip_height / 2))
                my_mlx_pixel_put(p, x , y, 0xabcdef);
            if (y > (int)(WINDOW_HEIGHT / 2 + wall_strip_height / 2))
                my_mlx_pixel_put(p, x , y, 0xfedcba);
            if (y < (int)(WINDOW_HEIGHT / 2 - wall_strip_height / 2))
                my_mlx_pixel_put(p, x , y, 0xfedcba);
            y++;
        }
        mlx_clear_window(p->mlx,p->mlx_win);
        mlx_put_image_to_window(p->mlx, p->mlx_win, p->img, 0, 0);
        x++;
    }

}