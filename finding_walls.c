#include "header.h"


int  distance_calc(int x1,int y1,int x2,int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
 

void  cast_rays(t_player *p)
{
    int i;
    int ray_id;
    // here we substruct 30 degres from p->rotation_angle  and add to ray_angle
    p->ray_angle = p->rotation_angle - (FOV_ANGLE / 2);
    i = 0;
    ray_id = 0;
    while (ray_id < NUM_OF_RAYS)
    {
        printf("%f\n",p->ray_angle);
        horizontal_intersection(p);
	    vertical_intersection(p);
        p->ray_angle +=  FOV_ANGLE / NUM_OF_RAYS;
        ray_id++;
    }
    



}
 
void intersections(t_player *p)
{
    int hor_distance;
    int vir_distance;

    

    cast_rays(p);

    
    
    // hor_distance = (p->find.h_found_wall) ? distance_calc(p->x,p->y,p->find.h_wall_hit_x,p->find.h_wall_hit_y) : 100000;
    // vir_distance = (p->find.v_found_wall) ? distance_calc(p->x,p->y,p->find.v_wall_hit_x,p->find.v_wall_hit_y) : 100000;

    // p->find.wall_hit_x = (hor_distance < vir_distance) ? p->find.h_wall_hit_x : p->find.v_wall_hit_x;
    // p->find.wall_hit_y = (hor_distance < vir_distance) ? p->find.h_wall_hit_y : p->find.v_wall_hit_y;
    // p->find.distance =  (hor_distance < vir_distance) ? hor_distance : vir_distance;




} 