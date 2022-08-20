#include "./includes/header.h"



void init_player_attributs(t_player  *p)
{
	p->x = 220;	
	p->y = 180;	
	p->turn = 0;
	p->walk = 0;
	p->rotation_angle = PI / 2;
	p->walk_speed = 5;
	p->turn_speed = 4 * (PI / 180);// 4 degres
	p->fov_angle = 60 * (PI / 180);
	p->num_of_rays = WINDOW_WIDTH / 1;
} 


 
int main(int argc, char *argv[])
{

	t_player pl;
	t_player  *p = &pl;
 
	p->mlx = mlx_init();
	p->mlx_win = mlx_new_window(p->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	
	// in function of key hook create update(), evry click will update the screen
	init_player_attributs(p);
	p->map.file = argv[1];
    put_walls(p);
 
	moves_of_player(p);

	mlx_loop(p->mlx);
    return 0;
}