#include "header.h"



static void find_steps_vertical(int is_face_l, t_player *p)
{
     
    if(is_face_l)
        p->find.v_next_vir_x--;
    p->find.v_found_wall = 0;
    while(point_in_range((int)(p->find.v_next_vir_x  / TILE_SIZE), (int)(p->find.v_next_vir_y  / TILE_SIZE)))
    {

        if(p->lines[(int)(p->find.v_next_vir_y  / TILE_SIZE) ][(int)(p->find.v_next_vir_x / TILE_SIZE)] == '1')
        {
    
            p->find.v_found_wall = 1;
            p->find.v_wall_hit_x = p->find.v_next_vir_x;
            p->find.v_wall_hit_y = p->find.v_next_vir_y;
             
            break;
        }
        else
        {
            p->find.v_next_vir_y += p->find.v_ystep;
            p->find.v_next_vir_x += p->find.v_xstep;
        }
    } 
}
 


void vertical_intersection(t_player *p)
{
    int     is_face_down;
    int     is_face_up;
    int     is_face_r;
    int     is_face_l;

    // p->ray_angle = p->rotation_angle;

	// find first closest ponit vertical
    p->find.v_xintercept = (int)(p->x / TILE_SIZE) * TILE_SIZE;
    p->find.v_yintercept = p->y + (( p->find.v_xintercept - p->x) * tan(p->ray_angle)); 
    
	is_face_up = p->ray_angle >= 0 && p->ray_angle <= PI;
    is_face_down =  !is_face_up;
    is_face_r = cos(p->ray_angle) >= 0 ? 1 : 0;
    is_face_l = !is_face_r;
    if(is_face_r)
        p->find.v_xintercept += TILE_SIZE;
    p->find.v_xstep = TILE_SIZE;       
    p->find.v_ystep = TILE_SIZE * tan(p->ray_angle);
 
    p->find.v_xstep *= is_face_l ? -1 : 1;
    p->find.v_ystep *=  (is_face_up && p->find.v_ystep > 0) ? -1 : 1;
    p->find.v_ystep *=  (is_face_down && p->find.v_ystep < 0) ? -1 : 1;
    p->find.v_next_vir_x = p->find.v_xintercept;
    p->find.v_next_vir_y = p->find.v_yintercept;
    find_steps_vertical(is_face_l,p);
} 