#include "../includes/header.h"

void	my_mlx_pixel_put(t_player *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void draw_floor_roof(t_player *p)
{
    int y;

    p->wall.floor_px = (int)(WINDOW_HEIGHT / 2 + p->wall.wall_strip_height / 2);
    y = p->wall.floor_px;
    while (y < WINDOW_HEIGHT)
    {
        my_mlx_pixel_put(p, p->wall.x , y, 0x58423C);
        y++;
    }
    p->wall.roof_px = (int)(WINDOW_HEIGHT / 2 - p->wall.wall_strip_height / 2);
    y = 0;
    while (y < p->wall.roof_px)
    { 
        my_mlx_pixel_put(p, p->wall.x , y, 0xfedcba);
        y++;
    }

}

static void init_rend(t_player *p)
{
    p->wall.wall_strip_width = WINDOW_WIDTH / p->num_of_rays;
    p->img = mlx_new_image(p->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, &p->line_length, &p->endian);
    p->wall.i = 0;
    p->wall.x = 0;
}

void rendering_walls(t_player *p)
{
    int y;
    char	*dst;
    init_rend(p);
    while (p->wall.x < WINDOW_WIDTH)
    {
        p->wall.distance_project_plane = (WINDOW_WIDTH / 2) / tan(p->fov_angle / 2);
        p->wall.wall_strip_height = (TILE_SIZE / p->distance[p->wall.i]) * p->wall.distance_project_plane;
        if (p->wall.x % p->wall.wall_strip_width == 0  && p->wall.x != 0)
            p->wall.i++;
        p->wall.wall_top_px = (int)(WINDOW_HEIGHT / 2 - p->wall.wall_strip_height / 2);   // if is negative assagne it the top of screen    
        p->wall.wall_top_px = p->wall.wall_top_px < 0 ? 0 : p->wall.wall_top_px;
        p->wall.wall_bottom_px =   (WINDOW_HEIGHT / 2 + p->wall.wall_strip_height / 2); 
        p->wall.wall_bottom_px = p->wall.wall_bottom_px  > WINDOW_HEIGHT ? WINDOW_HEIGHT : p->wall.wall_bottom_px;// protection
        y = p->wall.wall_top_px;
        while (y <  p->wall.wall_bottom_px)
        {
            dst = p->addr + (y * p->line_length + p->wall.x * (p->bits_per_pixel / 8));
            if(p->wall.x % 8 && y % 8)
                *(unsigned int*)dst = 0xabcdef;
            else
                *(unsigned int*)dst = 0x000000;
            y++;
        }
        draw_floor_roof(p);
        p->wall.x++;
    }
    // mlx_clear_w indow(p->mlx,p->mlx_win);
    mlx_put_image_to_window(p->mlx, p->mlx_win, p->img, 0, 0);

}







            // if (y > (int)(WINDOW_HEIGHT / 2 + p->wall.wall_strip_height / 2))
            //     my_mlx_pixel_put(p, x , y, 0xfedcba);
            // if (y < (int)(WINDOW_HEIGHT / 2 - p->wall.wall_strip_height / 2))
            //     my_mlx_pixel_put(p, x , y, 0xfedcba);