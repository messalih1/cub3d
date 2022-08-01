#include "header.h"


 
// void cast_ray(int id, t_player *p)
// {
//     int xintercept;
//     int yintercept;
//     int xstep;
//     int ystep;

//     yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
//     xintercept = p->x + (yintercept - p->y_intercept) / tan(p->ray_angle);

//     p->is_face_down = sin(p->ray_angle) < 0;
//     p->is_face_up = sin(p->ray_angle) >= 0;
//     p->is_face_l = sin(p->ray_angle) >= 0 && cos(p->ray_angle) ;
//     p->is_face_r = !p->is_face_l;

// }

void fiew_of_view(t_player *p)
{
	int xintercept;
    int yintercept;
    int xstep;
    int ystep;

    p->ray_angle = p->rotation_angle;
    yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
    xintercept = p->x + (yintercept - p->y_intercept) / tan(p->ray_angle);

    p->is_face_down = p->ray_angle < 2 * PI && p->ray_angle > PI;
    // p->is_face_up = sin(p->ray_angle) >= 0;
    // p->is_face_l = sin(p->ray_angle) >= 0 && cos(p->ray_angle) ;
    // p->is_face_r = !p->is_face_l;
    printf("%f\n",p->ray_angle);
     printf("%d\n",p->is_face_down);
}


//  Math.floor convert to int