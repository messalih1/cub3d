#include "header.h"


int  distance_calc(int x1,int y1,int x2,int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
 

float  *cast_rays(t_player *p)
{
    
    int i;
    float hor_distance;
    float vir_distance;
    float *distance;

    p->find.wall_hit_x = malloc(sizeof(float ) * NUM_OF_RAYS);
    p->find.wall_hit_y = malloc(sizeof(float ) * NUM_OF_RAYS);
     distance = malloc(sizeof(float ) * NUM_OF_RAYS);
    // here we substruct 30 degres from p->rotation_angle  and add to ray_angle
    p->ray_angle = p->rotation_angle - (FOV_ANGLE / 2);
    i = 0;
    while (i < NUM_OF_RAYS)
    {
 
        horizontal_intersection(p);
	    vertical_intersection(p);
        hor_distance = (p->find.h_found_wall) ? distance_calc(p->x,p->y,p->find.h_wall_hit_x,p->find.h_wall_hit_y) : 10000000.2222;
        vir_distance = (p->find.v_found_wall) ? distance_calc(p->x,p->y,p->find.v_wall_hit_x,p->find.v_wall_hit_y) : 10000000.000;

        p->find.wall_hit_x[i]  = (hor_distance < vir_distance) ? p->find.h_wall_hit_x : p->find.v_wall_hit_x;
        p->find.wall_hit_y[i]  = (hor_distance < vir_distance) ? p->find.h_wall_hit_y : p->find.v_wall_hit_y;
        
        distance[i] =  (hor_distance < vir_distance) ? hor_distance : vir_distance;
        p->ray_angle += ( FOV_ANGLE / NUM_OF_RAYS);
        i++;
    }
    return  distance;
}



void	my_mlx_pixel_put(t_player *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void intersections(t_player *p)
{
    
    float *distance = cast_rays(p);
     
     
    int i = 0;
    int x = 0;
    int y;

    
    int s = WINDOW_WIDTH / NUM_OF_RAYS;
    p->img = mlx_new_image(p->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, &p->line_length, &p->endian);
    while (x < WINDOW_WIDTH)
    {
        float distance_project_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
        float wall_strip_height = (TILE_SIZE / distance[i]) * distance_project_plane;
        if (x % s == 0 && x != 0)
            i++;
        y = 0;
        // printf (">%f\n",distance[i]);
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