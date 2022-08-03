#include "header.h"


#include "header.h"

int main(int argc, char *argv[])
{
	t_m p;
	t_player pl;
	t_player  *play = &pl;
	t_m *m = &p;
 
	 
	play->mlx = mlx_init();
	play->mlx_win = mlx_new_window(play->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	put_walls(m,play,argv[1]);

	palyer_movement(m,play);
	
// cos(p->rotation_angle) * 2 ; 
//     p->y -= sin(p->rotation_angle) * 2 ;

	// play->rotation_angle = 5 * PI / 6 ;
 
	// printf("%f\n",sin(play->rotation_angle) );

	
 
	
	

	mlx_loop(play->mlx);
    return 0;
}