#include "../includes/header.h"



void move_player(t_player *p)
{
    alloc_lines(p);

     
    p->distance = malloc(sizeof(double) * p->num_of_rays);
    p->ver.distance = malloc(sizeof(double) * p->num_of_rays);
    p->hor.distance = malloc(sizeof(double) * p->num_of_rays);
    p->px = malloc(sizeof(double) * p->num_of_rays);
    p->py = malloc(sizeof(double) * p->num_of_rays);
    p->if_is_vertical = malloc(sizeof(int) * p->num_of_rays);
    p->ver.i = 0;
    p->hor.i = 0;
    p->ray_angle = p->rotation_angle - (p->fov_angle / 2);
    p->angle_ray = malloc(sizeof(double) * p->num_of_rays);
    find_intersections(p,0);
     
}


int	key_hook_(t_player *p, int keycode)
{
    float move_step;
    
    if(keycode == 1)// s
    {
        p->walk = -1;
        move_step = p->walk * p->walk_speed;
        p->x += cos(p->rotation_angle) * move_step; 
        p->y += sin(p->rotation_angle) * move_step;
    }
    if(keycode == 2)// a
    {
        p->move = -1;
        move_step = p->move * p->walk_speed;
        p->x += cos(p->rotation_angle) + move_step;
    }
    if(keycode == 0) // d
    {
        p->move = +1;
        move_step = p->move * p->walk_speed;
        p->x += cos(p->rotation_angle) + move_step;
    }
    move_player(p);
    return (0);
}

int	key_hook(int keycode, t_player *p)
{
    float move_step;

    if(keycode == 124) 
    {
        p->turn = +1;
        p->rotation_angle += p->turn * p->turn_speed;
    }
    if(keycode == 123) 
    {
        p->turn = -1;
        p->rotation_angle += p->turn * p->turn_speed;
    }
    if(keycode == 13)// w
    {
        p->walk = +1;
        move_step = p->walk * p->walk_speed;
        p->x += cos(p->rotation_angle) * move_step; 
        p->y += sin(p->rotation_angle) * move_step;
    }
    return key_hook_(p,keycode);
}

 
 
int moves_of_player(t_player *p)
{
     
    mlx_hook(p->mlx.mlx_win, 02, 1L<<0, key_hook, p); 
     

    return 1;
}