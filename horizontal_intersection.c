#include "header.h"

  

int point_in_range(float x, float y)
{
	return (x >= 0 && x <  MAP_NUM_COLS && y >= 0 && y <  MAP_NUM_ROWS);
}



static void find_steps_horizontal(int is_face_up, t_player *p)
{
    
    if(is_face_up)
        p->find.h_next_hor_y--;
    p->find.h_found_wall = 0;
    while(point_in_range((int)(p->find.h_next_hor_x / TILE_SIZE),(int)(p->find.h_next_hor_y  / TILE_SIZE)))
    {
        if(p->lines[(int)(p->find.h_next_hor_y  / TILE_SIZE) ][(int)(p->find.h_next_hor_x / TILE_SIZE)] == '1')
        {
            // ddadraw(p->x,p->y,p->find.h_next_hor_x,p->find.h_next_hor_y,p);
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

void horizontal_intersection(t_player *p)
{
    int     is_face_down;
    int     is_face_up;
    int     is_face_r;
    int     is_face_l;

    
    p->find.h_yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
  
    p->find.h_xintercept = p->x + (p->find.h_yintercept - (p->y)) / tan(p->ray_angle); 
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
    
    find_steps_horizontal(is_face_up,p);
}