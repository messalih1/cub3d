#include "header.h"
# include <mlx.h>



// walls 
// space black



int main(int argc, char *argv[])
{
	t_m p;
	t_m *m = &p;
	t_data	im;
	t_data	*img = &im;
	 

	img->mlx = mlx_init();

	img->mlx_win = mlx_new_window(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	
	put_walls(m,img,argv[1]);

	mlx_loop(img->mlx);

    return 0;
}