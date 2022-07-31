#include "header.h"


 
void cast_ray(int id, t_player *p)
{
    int xintercept;
    int yintercept;
    int xstep;
    int ystep;

    yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
    xintercept = p->x + (yintercept - p->y_intercept) / tan(p->ray_angle);

    p->is_face_down = sin(p->ray_angle) < 0;
    p->is_face_up = sin(p->ray_angle) >= 0;
    p->is_face_l = sin(p->ray_angle) >= 0 && cos(p->ray_angle) ;
    p->is_face_r = !p->is_face_l;

}

void fiew_of_view(t_player *p)
{
	int ray_id;
	int i;

	ray_id = 0;
    //              pi / 2  90 - 60 / 2   
	p->ray_angle = p->rotation_angle;// you can alloc by number of rays and assign the values by indexws to access
	 
	cast_ray(ray_id, p);
   
     
}


//  Math.floor convert to int