#include "./includes/header.h"



void init_player_attributs(t_player  *p,char *map)
{
	p->x = 500;	
	p->y = 180;	
	p->turn = 0;
	p->walk = 0;
	p->move = 0;
	p->rotation_angle = PI / 2;
	p->walk_speed = 5;
	p->turn_speed = 4 * (PI / 180);// 4 degres
	p->fov_angle = 60 * (PI / 180);
	p->num_of_rays = WINDOW_WIDTH;
	p->map.file = map;
} 


 
int main(int argc, char *argv[])
{
	t_player pl;
	t_player  *p = &pl;
 
	p->mlx.mlx = mlx_init();
	p->mlx.mlx_win = mlx_new_window(p->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
 	  
 	init_player_attributs(p,argv[1]);
	
 
	moves_of_player(p);

	mlx_loop(p->mlx.mlx);
    return 0;
}