#include "header.h"
// # include <mlx.h>



// walls 
// space black


// circle(thid, this.y, this.redius) here use mlx_xpm_file_to_image()
int main(int argc, char *argv[])
{
	t_m p;
	t_player pl;
	t_player  *play = &pl;
	t_m *m = &p;
	t_data	im;
	t_data	*img = &im;
	 
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	put_walls(m,img,argv[1]);

	palyer_movement(m,img, play);




	mlx_loop(img->mlx);
    return 0;
}