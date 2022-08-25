#include "./includes/header.h"



void init_player_attributs(t_player  *p)
{
	p->x = 500;	
	p->y = 180;	
	p->turn = 0;
	p->walk = 0;
	p->rotation_angle = PI / 2;
	p->walk_speed = 5;
	p->turn_speed = 4 * (PI / 180);// 4 degres
	p->fov_angle = 60 * (PI / 180);
	p->num_of_rays = WINDOW_WIDTH / 1;
} 


// unsigned int	img_color(t_img *t, int x, int y)
// {
// 	int		offset;
// 	char	*img_pix;
// 	uint32_t	color;

// 	offset = y * t->sl + x * (t->bpp / 8);//memory offset (line_length differs from the actual window width)
	
// 	img_pix = t->addr + offset;
// 	if (!img_pix)
// 	{
// 		printf("Error in puting pixel's color!\n");
// 		exit(0);
// 	}
// 	color = (((unsigned char)img_pix[2] << 16) + ((unsigned char)img_pix[1] << 8) + (unsigned char)img_pix[0]);
// 	if (color)
// 		return (color);
// 	else
// 		return ((unsigned int)4732952);
// }


 
int main(int argc, char *argv[])
{

	t_player pl;
	t_player  *p = &pl;
 
 
	p->mlx.mlx = mlx_init();
	p->mlx.mlx_win = mlx_new_window(p->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	
	//   p->mlx.img = mlx_new_image(p->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// p->mlx.addr = mlx_get_data_addr(p->mlx.img, &p->mlx.bits_per_pixel, &p->mlx.line_length, &p->mlx.endian);
    
	// int x;
	// int y;
    // p->mlx.img_px = mlx_xpm_file_to_image(p->mlx.mlx,"./img.xpm", &x, &y);
	// p->mlx.addr_px = mlx_get_data_addr(p->mlx.img_px, &p->mlx.bpp, &p->mlx.sl, &p->mlx.l);
	// char *dst;
	// char *src;

	// x = 0;

	// while (x < 100)
	// {
	// 	y = 0;
	// 	while (y < 100)
	// 	{
	// 		dst = p->mlx.addr + (y * p->mlx.line_length + x * (p->mlx.bits_per_pixel / 8));
    //     	src = p->mlx.addr_px + (y * p->mlx.sl + x * (p->mlx.bpp / 8));
    //         *(unsigned int*)dst =  *(unsigned int*)src;// return the px color

			 
	// 	}
		
	// 	x++;
	// }
	
	 
    mlx_put_image_to_window(p->mlx.mlx, p->mlx.mlx_win, p->mlx.img, 0, 0);

 	init_player_attributs(p);
	p->map.file = argv[1];
 
	moves_of_player(p);

	mlx_loop(p->mlx.mlx);
    return 0;
}