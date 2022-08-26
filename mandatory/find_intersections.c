#include "../includes/header.h"


int point_in_range(float x, float y)
{
	return (x >= 0 && x <= WINDOW_WIDTH && y >= 0 && y <= WINDOW_HEIGHT);
}
 

void normalize_angle(t_player *p)
{
    if (p->ray_angle >= 2 * PI)
        p->ray_angle -= 2 * PI; 
    if (p->ray_angle <= 0)
        p->ray_angle += 2 * PI;
}
// calc Hypotenuse الوتر أطول ضلع في مثلث قائم الزاوية
double  distance_calc(double x1,double y1,double x2,double y2)
{
    //                  oss 2                   oss 2
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



void find_intersections(t_player *p, int i)
{
    while (i < p->num_of_rays)
    {
        normalize_angle(p);
        horizontal_intersections(p);
        vertical_intersections(p);
        p->angle_ray[i] = p->ray_angle;
        p->distance[i] = (p->ver.distance[p->ver.i - 1] < p->hor.distance[p->hor.i - 1]) ? p->ver.distance[p->ver.i - 1] : p->hor.distance[p->hor.i - 1];
        if(p->ver.distance[p->ver.i - 1] < p->hor.distance[p->hor.i - 1])
        {
            p->if_is_vertical[i] = 1;
            p->px[i] = p->ver.wall_hit_x; 
            p->py[i] = p->ver.wall_hit_y; 
        }
        else
        {
            p->if_is_vertical[i] = 0;
            p->px[i] = p->hor.wall_hit_x; 
            p->py[i] = p->hor.wall_hit_y;
        }
        p->ray_angle += (p->fov_angle / p->num_of_rays);
        i++;
    }
    rendering_walls(p);     
}



 

 

 