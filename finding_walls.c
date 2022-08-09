#include "header.h"


 

// // void x_y_horizontal_step(t_player *p)
// // {
// //     int is_face_down;
// //     int    is_face_up;
// //     int is_face_r;
// //     int is_face_l;

     

// //     p->ray_angle = p->rotation_angle;
// //     p->yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
// //     p->xintercept = p->x + ((p->y - p->yintercept) / tan(p->ray_angle));// or tan (p->ray_angle)
     
// //     is_face_up = p->ray_angle >= 0 && p->ray_angle <= PI;
// //     is_face_down =  !is_face_up;
// //     is_face_r = cos(p->ray_angle) >= 0 ? 1 : 0;
// //     is_face_l = !is_face_r;
// //     if(is_face_down)
// //         p->yintercept += TILE_SIZE;
    
   
// //     p->ystep = TILE_SIZE;
// //     p->xstep =  (TILE_SIZE / tan(p->ray_angle)); 

     
// //     p->ystep *=  is_face_up ? -1 : 1;
  
// //     p->xstep *=  (is_face_r && p->xstep < 0) ? -1 : 1;
// //     p->xstep *=  (is_face_l && p->xstep > 0) ? -1 : 1;


// //     p->next_hor_x = p->xintercept;
// //     p->next_hor_y = p->yintercept;

// //     if(is_face_up)
// //         p->next_hor_y--;
 
  
// //     while(1)
// //     {
// //         if(p->lines[(int)(p->next_hor_y  / TILE_SIZE) ][(int)(p->next_hor_x / TILE_SIZE)] == '1')
// //         {
// //             p->found_wall = 1;
// //             p->wall_hit_x = p->next_hor_x;
// //             p->wall_hit_y = p->next_hor_y;
// //             printf("WALL\n");
// //             break;
// //         }
// //         else
// //         {
// //             p->next_hor_y += p->ystep;
// //             p->next_hor_x += p->xstep;
// //         }
// //     } 
     
// // }
 
void find_steps(int is_face_up, t_player *p)
{
    
    if(is_face_up)
        p->find.h_next_hor_y--;
    while(1)
    {
        if(p->lines[(int)(p->find.h_next_hor_y  / TILE_SIZE) ][(int)(p->find.h_next_hor_x / TILE_SIZE)] == '1')
        {
            p->find.h_found_wall = 1;
            p->find.h_wall_hit_x = p->find.h_next_hor_x;
            p->find.h_wall_hit_y = p->find.h_next_hor_y;
            break;
        }
        else
        {
            p->find.h_next_hor_y += p->find.h_ystep;
            p->find.h_next_hor_x += p->find.h_xstep;
        }
    } 
}
void find_walls(t_player *p)
{
    int     is_face_down;
    int     is_face_up;
    int     is_face_r;
    int     is_face_l;

    p->ray_angle = p->rotation_angle;
    p->find.h_yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
  
    p->find.h_xintercept = p->x + ((p->y - p->find.h_yintercept) / tan(p->ray_angle)); 
    is_face_up = p->ray_angle >= 0 && p->ray_angle <= PI;
    is_face_down =  !is_face_up;
    is_face_r = cos(p->ray_angle) >= 0 ? 1 : 0;
    is_face_l = !is_face_r;
    if(is_face_down)
        p->find.h_yintercept += TILE_SIZE;
    p->find.h_ystep = TILE_SIZE;
    p->find.h_xstep =  (TILE_SIZE / tan(p->ray_angle));      
    p->find.h_ystep *=  is_face_up ? -1 : 1;
    p->find.h_xstep *=  (is_face_r && p->find.h_xstep < 0) ? -1 : 1;
    p->find.h_xstep *=  (is_face_l && p->find.h_xstep > 0) ? -1 : 1;
    p->find.h_next_hor_x = p->find.h_xintercept;
    p->find.h_next_hor_y = p->find.h_yintercept;
    
    find_steps(is_face_up,p);
}
void find_steps_(int is_face_l, t_player *p)
{
     
    // if(is_face_l)
    //     p->find.v_next_vir_x--;
    // while(1)
    // {
    //     if(p->lines[(int)(p->find.v_next_vir_y  / TILE_SIZE) ][(int)(p->find.v_next_vir_x / TILE_SIZE)] == '1')
    //     {
    //         p->find.v_found_wall = 1;
    //         p->find.v_wall_hit_x = p->find.v_next_vir_x;
    //         p->find.v_wall_hit_y = p->find.v_next_vir_y;
    //         printf("WALLL\n");
    //         break;
    //     }
    //     else
    //     {
    //         p->find.v_next_vir_y += p->find.v_ystep;
    //         p->find.v_next_vir_x += p->find.v_xstep;
    //     }
    // } 
}
 


void find_walls_(t_player *p)
{
    int     is_face_down;
    int     is_face_up;
    int     is_face_r;
    int     is_face_l;

     p->ray_angle = p->rotation_angle;

	// find first closest ponit vertical
    p->find.v_xintercept = (int)(p->x / TILE_SIZE) * TILE_SIZE;
    p->find.v_yintercept = p->y + ((p->find.v_xintercept - p->x) * tan(p->ray_angle)); 
    
	is_face_up = p->ray_angle >= 0 && p->ray_angle <= PI;
    is_face_down =  !is_face_up;
    is_face_r = cos(p->ray_angle) >= 0 ? 1 : 0;
    is_face_l = !is_face_r;
    if(is_face_r)
        p->find.v_xintercept += TILE_SIZE;
    p->find.v_xstep = TILE_SIZE;       
    p->find.v_ystep = TILE_SIZE * tan(p->ray_angle);
    if(!p->find.v_ystep)
        printf("WWW\n");
    p->find.v_xstep *= is_face_l ? -1 : 1;
    p->find.v_ystep *=  (is_face_up && p->find.v_ystep > 0) ? -1 : 1;
    p->find.v_ystep *=  (is_face_down && p->find.v_ystep < 0) ? -1 : 1;
    p->find.v_next_vir_x = p->find.v_xintercept;
    p->find.v_next_vir_y = p->find.v_yintercept;
    find_steps_(is_face_l,p);
}
 
void cast_ray(t_player *p)
{
  

    // find_walls(p);
    find_walls_(p);
    
    
    // x_y_vertical_step(p);
	
    
}


// //  Math.floor convert to int