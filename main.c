#include "header.h"


// void    put_wall(t_rend m, int wall_h, int i, int c)
// {
//     t_img    img;
// 	char *dst;
//     int        y;
//     int        x;

//     img.img = mlx_new_image(m->mlx, 2, wall_h);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//             &img.endian);
//    // new_x_y(&img, m, i);
//     y = 0;
//     while (y != wall_h)
//     {
//         //img.newy = ((y) ((float)WALL_SIZE / (float)wall_h));
//             // img.dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel
//             //             / 8));
//             // (unsigned int)img.dst = m->buffer[c][(64 * img.newy) + img.newx];
// 		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
//         y++;
//     }
   
// }
int main(int argc, char *argv[])
{
	t_m p;
	t_player pl;
	t_player  *play = &pl;
	t_m *m = &p;
 
	 
	play->mlx = mlx_init();
	play->mlx_win = mlx_new_window(play->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	// play->img = mlx_new_image(play->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// play->addr = mlx_get_data_addr(play->img, &play->bits_per_pixel, &play->line_length, &play->endian);
	put_walls(m,play,argv[1]);
	palyer_movement(m,play);
	mlx_loop(play->mlx);
	
    return 0;
}