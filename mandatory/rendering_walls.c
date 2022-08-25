#include "../includes/header.h"


void return_y(t_player *p)
{
    int x;
    int y;

    p->wall.distance_project_plane = (WINDOW_WIDTH / 2) / tan(p->fov_angle / 2);
    p->wall.wall_strip_height = (TILE_SIZE / p->distance[p->wall.i]) * p->wall.distance_project_plane;
    if (p->wall.x % p->wall.wall_strip_width == 0  && p->wall.x != 0)
        p->wall.i++;
    p->wall.wall_top_px = (int)(WINDOW_HEIGHT / 2 - p->wall.wall_strip_height / 2);   // if is negative assagne it the top of screen    
    p->wall.wall_top_px = p->wall.wall_top_px < 0 ? 0 : p->wall.wall_top_px;
    p->wall.wall_bottom_px =   (WINDOW_HEIGHT / 2 + p->wall.wall_strip_height / 2); 
    p->wall.wall_bottom_px = p->wall.wall_bottom_px  > WINDOW_HEIGHT ? WINDOW_HEIGHT : p->wall.wall_bottom_px;// protection
     
    
    // return p->wall.wall_top_px;
}

static int init_rend(t_player *p)
{
    int x;
    int y;

    p->wall.wall_strip_width = WINDOW_WIDTH / p->num_of_rays;

    p->mlx.img = mlx_new_image(p->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	p->mlx.addr = mlx_get_data_addr(p->mlx.img, &p->mlx.bits_per_pixel, &p->mlx.line_length, &p->mlx.endian);
    
    p->mlx.img_px = mlx_xpm_file_to_image(p->mlx.mlx,"./img.xpm", &x, &y);
	p->mlx.addr_px = mlx_get_data_addr(p->mlx.img_px, &p->mlx.bpp, &p->mlx.sl, &p->mlx.l);
    p->wall.i = 0;
    p->wall.x = 0;
    return (x);
}

	 


void rendering_walls(t_player *p)
{
    int i,j,h;
    int y;
    int     x_offset;
    int     y_offset;
    char	*dst;
    char	*src;

    h = init_rend(p); 
    while (p->wall.x < WINDOW_WIDTH)
    {
        return_y(p);
        y = p->wall.wall_top_px;
        if(p->if_is_vertical[p->wall.i])
        {
            x_offset = (int)p->py[p->wall.i] % TILE_SIZE;
            i = (fmod(p->py[p->wall.i], 64)) * (h / 64);
        }
        else
        {
            x_offset = (int)p->px[p->wall.i] % TILE_SIZE;
            i = (fmod(p->px[p->wall.i], 64)) * (h / 64);
        }

        while (y <  p->wall.wall_bottom_px)
        { 
            y_offset = (y - p->wall.wall_top_px) * ( (64 / p->wall.wall_strip_height));
            j = (y - p->wall.wall_top_px) * ( (h / p->wall.wall_strip_height));
            dst = p->mlx.addr + (y * p->mlx.line_length + p->wall.x * (p->mlx.bits_per_pixel / 8));
            src = p->mlx.addr_px + (j * p->mlx.sl + i * (p->mlx.bpp / 8));
        
            *(unsigned int*)dst =  *(unsigned int*)src; 
           
            y++;
        }
        draw_floor_roof(p);
        p->wall.x++;
    }
    // mlx_clear_window(p->mlx.mlx,p->mlx.mlx_win);
    mlx_put_image_to_window(p->mlx.mlx, p->mlx.mlx_win, p->mlx.img, 0, 0);

}

 