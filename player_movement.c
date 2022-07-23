#include "header.h"


void init_(t_player *p,t_data *m)
{
    p->x = WINDOW_WIDTH / 2;
    p->y = WINDOW_HEIGHT / 2;
    p->radius = 3;
    p->turn_direcrtion = 0; // -1 if left, +1 if right
    p->walk_direcrtion = 0; // -1 if back, +1 if front
    p->rotation_angle  = PI / 2; // 90 helf of round
    p->move_speed = 2.0; // to update place player pixels  
    p->rotaion_speed = 2 * (PI / 180); // سرعة الدوران 
    m->red_img = "./red.xpm";
    m->img = mlx_xpm_file_to_image(m->mlx, m->red_img, &m->line_length, &m->endian);
    mlx_put_image_to_window(m->mlx, m->mlx_win, m->img ,p->x,p->y);
}

int	key_hook(int keycode, t_player *p)
{
    if (keycode == 2)
		p->turn_direcrtion = +1;
	else if (keycode == 0)
		p->turn_direcrtion = -1;
	else if (keycode == 1)
		p->walk_direcrtion = -1;
	else if (keycode == 13)
		p->walk_direcrtion = +1; 
    printf("%d\n",p->walk_direcrtion);
	return (0);
}

int	key_relese(int keycode, t_player *p)
{
    if (keycode == 2)
		p->turn_direcrtion = 0;
	else if (keycode == 0)
		p->turn_direcrtion = 0;
	else if (keycode == 1)
		p->walk_direcrtion = 0;
	else if (keycode == 13)
		p->walk_direcrtion = 0; 
    printf("%d\n",p->walk_direcrtion);
    
	return (0);
}

void palyer_movement(t_m *m, t_data *img, t_player *p)
{
    init_(p,img);
    mlx_hook(img->mlx_win, 02, 1L<<0, key_hook, p);// relese
	mlx_hook(img->mlx_win, 03, 1L<<1, key_relese, p);
   

}