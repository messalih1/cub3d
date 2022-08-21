#include "../includes/header.h"

 

int move_player(t_player *p)
{
    // mlx_clear_window(p->mlx,p->mlx_win);
    
    // drawDDA(p->x,p->y,p->x + cos(p->rotation_angle) * 60,p->y+sin(p->rotation_angle) * 60,p);
    find_intersections(p);
    

    return 1;
}


int	key_hook(int keycode, t_player *p)
{
    if(keycode == 0)// d
    {
        p->turn = -1;
        p->rotation_angle += p->turn * p->turn_speed;
    }
    if(keycode == 2)// a
    {
        p->turn = +1;
        p->rotation_angle += p->turn * p->turn_speed;
    }
    if(keycode == 1)// w
    {
        p->walk = -1;
        float move_step = p->walk * p->walk_speed;
        p->x += cos(p->rotation_angle) * move_step; 
        p->y += sin(p->rotation_angle) * move_step;
    }
    if(keycode == 13)// s
    {
        p->walk = +1;
        float move_step = p->walk * p->walk_speed;
        p->x += cos(p->rotation_angle) * move_step; 
        p->y += sin(p->rotation_angle) * move_step;
    }
    // if (p->rotation_angle >= 2 * PI)
    //     p->rotation_angle -= 2 * PI; 
    // if (p->rotation_angle <= 0)
    //     p->rotation_angle += 2 * PI;

 
    move_player(p);
    return (0);
}

 
int	key_hook_relese(int keycode, t_player *p)
{ 
  
    if(keycode == 2) 
        p->turn = 0;
    if(keycode == 0)  
        p->turn = 0;
    if(keycode == 13) 
        p->walk = 0;
    if(keycode == 1) 
        p->walk = 0;
    return (0);
}

int moves_of_player(t_player *p)
{
     
    mlx_hook(p->mlx_win, 02, 1L<<0, key_hook, p);
    mlx_hook(p->mlx_win, 03, 1L<<1, key_hook_relese, p);
     

    return 1;
}