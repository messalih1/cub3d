#include "header.h"


// void check_walls_horizontal(t_player *p)
// {

//     // while (1)
//     // {
//         // if()
//         // {

//             if(p->next_hor_y == )
//         // }
//         // else
//         // {
//         p->next_hor_x +=  p->xstep;
//         p->next_hor_y +=  p->ystep;
//         // }
//         printf("%d\n",p->next_hor_y);
//     // }
    

// }

void x_y_horizontal_step(t_player *p)
{
    int is_face_down;
    int    is_face_up;
    int is_face_r;
    int is_face_l;

    p->ray_angle = p->rotation_angle;
    p->yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
    p->xintercept = p->x + ((p->y - p->yintercept) / tan(p->ray_angle));// or tan (p->ray_angle)
    is_face_up = p->ray_angle >= 0 && p->ray_angle <= PI;
    is_face_down =   is_face_up;
    is_face_r = p->ray_angle <= PI / 2 || p->ray_angle >= (3 * PI) / 2;
    is_face_l = p->ray_angle >= PI / 2 && p->ray_angle <= (3 * PI) / 2;
    p->yintercept += is_face_down ? TILE_SIZE : 0;
    p->ystep = TILE_SIZE;
    p->xstep = TILE_SIZE / tan(p->ray_angle);// or tan (p->ray_angle)
    p->ystep *=    is_face_up ? -1 : 1;
    p->xstep *= is_face_l  ? -1 : 1;
    p->xstep *=  is_face_r ? 1 : -1;
    p->next_hor_x = p->xintercept;
    p->next_hor_y = p->yintercept;
    if(is_face_up)
        p->next_hor_y--;
    // while(1)
    // {
    //     if()
    //     {


    //     }
    //     else
    //     {
    //        p->next_hor_x +=  p->xstep;
    //        p->next_hor_y +=  p->ystep; 
    //     }
    // }    
    // printf("%d\n",p->next_hor_y);
    // check_walls_horizontal(p);
}

void x_y_vertical_step(t_player *p)
{
    int is_face_down;
    int    is_face_up;
    int is_face_r;
    int is_face_l;

    p->ray_angle = p->rotation_angle;
    p->yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
    p->xintercept = p->x + ((p->y - p->yintercept) / tan(PI / 3));// or tan (p->ray_angle)
    is_face_up = p->ray_angle >= 0 && p->ray_angle <= PI;
    is_face_down =   is_face_up;
    is_face_r = p->ray_angle <= PI / 2 || p->ray_angle >= (3 * PI) / 2;
    is_face_l = p->ray_angle >= PI / 2 && p->ray_angle <= (3 * PI) / 2;
    p->yintercept += is_face_down ? TILE_SIZE : 0;
    p->ystep = TILE_SIZE;
    p->xstep = TILE_SIZE / tan(PI / 3);// or tan (p->ray_angle)
    p->ystep *=    is_face_up ? -1 : 1;
    p->xstep *= is_face_l  ? -1 : 1;
    p->xstep *=  is_face_r ? 1 : -1;

}

 
void cast_ray(t_player *p)
{
    

    x_y_horizontal_step(p);
    
    
    // x_y_vertical_step(p);
	
    
}


//  Math.floor convert to int