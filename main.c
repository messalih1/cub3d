#include "header.h"


#include "header.h"

int main(int argc, char *argv[])
{
	 
	t_player  *play = malloc(sizeof(play));
	
	play->find = malloc(sizeof(play->find));
	play->map = malloc(sizeof(play->map));
	
	 
	play->mlx = mlx_init();
	play->mlx_win = mlx_new_window(play->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
     
	put_walls(play->map,play,argv[1]);
  
	 
 	
	// palyer_movement(play->map,play);
	
 
	// play->map->i = 10;

	// printf("%d\n",play->map->i);
	
 
	
	

	mlx_loop(play->mlx);
    return 0;
}