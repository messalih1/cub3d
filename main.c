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
	
 
	

 	init_player_attributs(p);
	p->map.file = argv[1];
 
	moves_of_player(p);

	mlx_loop(p->mlx.mlx);
    return 0;
}