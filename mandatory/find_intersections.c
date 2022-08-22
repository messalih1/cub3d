#include "../includes/header.h"


int point_in_range(float x, float y)
{
	return (x >= 0 && x <  MAP_NUM_COLS && y >= 0 && y <  MAP_NUM_ROWS);
}


 

void normalize_angle(t_player *p)
{
    if (p->ray_angle >= 2 * PI)
        p->ray_angle -= 2 * PI; 
    if (p->ray_angle <= 0)
        p->ray_angle += 2 * PI;
}

double  distance_calc(double x1,double y1,double x2,double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void find_intersections(t_player *p)
{
    int i;

    p->distance = malloc(sizeof(double) * p->num_of_rays);
    p->ver.distance = malloc(sizeof(double) * p->num_of_rays);
    p->hor.distance = malloc(sizeof(double) * p->num_of_rays);

    i = 0;
    p->ver.i = 0;
    p->hor.i = 0;
    p->ray_angle = p->rotation_angle - (p->fov_angle / 2);
    while (i < p->num_of_rays)
    {
        normalize_angle(p);
        
        horizontal_intersections(p);
        vertical_intersections(p);
        p->distance[i] = (p->ver.distance[p->ver.i - 1] < p->hor.distance[p->hor.i - 1]) ? p->ver.distance[p->ver.i - 1] : p->hor.distance[p->hor.i - 1];
        p->ray_angle += (p->fov_angle / p->num_of_rays);
        i++;
    }
    rendering_walls(p);
      

}



 

 

 