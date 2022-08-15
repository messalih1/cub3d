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
	// play->img = mlx_new_image(play->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// play->addr = mlx_get_data_addr(play->img, &play->bits_per_pixel, &play->line_length,
	// 							&play->endian);
	put_walls(m,play,argv[1]);
	palyer_movement(m,play);
	mlx_loop(play->mlx);
	
    return 0;
}