#include "../includes/header.h"



static void init_rend(t_player *p)
{
    int x;
    int y;

    p->wall.wall_strip_width = WINDOW_WIDTH / p->num_of_rays;
    p->mlx.img = mlx_new_image(p->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	p->mlx.addr = mlx_get_data_addr(p->mlx.img, &p->mlx.bits_per_pixel, &p->mlx.line_length, &p->mlx.endian);
    p->wall.i = 0;
    p->wall.x = 0;
    p->mlx.img_px = mlx_xpm_file_to_image(p->mlx.mlx,"./wall.xpm", &x, &y);
	p->mlx.addr_px = mlx_get_data_addr(p->mlx.img_px, &p->mlx.bpp, &p->mlx.sl, &p->mlx.l);
}

	 

int return_y(t_player *p)
{
    p->wall.distance_project_plane = (WINDOW_WIDTH / 2) / tan(p->fov_angle / 2);
    p->wall.wall_strip_height = (TILE_SIZE / p->distance[p->wall.i]) * p->wall.distance_project_plane;
    if (p->wall.x % p->wall.wall_strip_width == 0  && p->wall.x != 0)
        p->wall.i++;
    p->wall.wall_top_px = (int)(WINDOW_HEIGHT / 2 - p->wall.wall_strip_height / 2);   // if is negative assagne it the top of screen    
    p->wall.wall_top_px = p->wall.wall_top_px < 0 ? 0 : p->wall.wall_top_px;
    p->wall.wall_bottom_px =   (WINDOW_HEIGHT / 2 + p->wall.wall_strip_height / 2); 
    p->wall.wall_bottom_px = p->wall.wall_bottom_px  > WINDOW_HEIGHT ? WINDOW_HEIGHT : p->wall.wall_bottom_px;// protection
    return p->wall.wall_top_px;
}

void rendering_walls(t_player *p)
{
    int y;
    int     x_offset;
    int     y_offset;
    char	*dst;
    char	*src;

    init_rend(p); 
    while (p->wall.x < WINDOW_WIDTH)
    {
        y = return_y(p);
        if(p->if_is_vertical[p->wall.i])
        { 

            y_offset = (int)p->py[p->wall.i] % TILE_SIZE;
            x_offset = 0;
            while (y <  p->wall.wall_bottom_px)
            {
                dst = p->mlx.addr + (y * p->mlx.line_length + p->wall.x * (p->mlx.bits_per_pixel / 8));
                src = p->mlx.addr_px + (y_offset * p->mlx.sl + x_offset * (p->mlx.bpp / 8));
            
                *(unsigned int*)dst =  *(unsigned int*)src;// return the px color
                if(y_offset % TILE_SIZE == 0)
                    y_offset++;
                y++;
            }
        }
        else
        {
            x_offset = (int)p->px[p->wall.i] % TILE_SIZE;
            y_offset = 0;
            while (y <  p->wall.wall_bottom_px)
            {
                dst = p->mlx.addr + (y * p->mlx.line_length + p->wall.x * (p->mlx.bits_per_pixel / 8));
                src = p->mlx.addr_px + (y_offset * p->mlx.sl + x_offset * (p->mlx.bpp / 8));
                
                *(unsigned int*)dst =  *(unsigned int*)src;// return the px color
                
                if(x_offset % TILE_SIZE == 0)
                    x_offset++;
               y++;
            }
        }
        
        draw_floor_roof(p);
        p->wall.x++;
    }
    // mlx_clear_w indow(p->mlx,p->mlx_win);
    mlx_put_image_to_window(p->mlx.mlx, p->mlx.mlx_win, p->mlx.img, 0, 0);

}

 