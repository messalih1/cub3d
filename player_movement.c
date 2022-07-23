#include "header.h"


void init_(t_player *p )
{
    int i;
    
    i = 0;
    p->x = WINDOW_WIDTH / 2;
    p->y = WINDOW_HEIGHT / 2;
    p->radius = 3;
    p->turn_direcrtion = 0; // -1 if left, +1 if right
    p->walk_direcrtion = 0; // -1 if back, +1 if front
    p->rotation_angle  = PI / 2; // 90 helf of round
    p->move_speed = 2.0; // to update place player pixels  
    p->rotaion_speed = 2 * (PI / 180); // سرعة الدوران 
    p->red_img = "./red.xpm";
    p->img = mlx_xpm_file_to_image(p->mlx, p->red_img, &p->line_length, &p->endian);
    mlx_put_image_to_window(p->mlx, p->mlx_win, p->img ,p->x,p->y);
    p->red_img = "./line.xpm";
    p->img = mlx_xpm_file_to_image(p->mlx, p->red_img, &p->line_length, &p->endian);
    

    
}

int	key_hook(int keycode, t_player *p)
{
    if (keycode == 2)
    {
        mlx_put_image_to_window(p->mlx, p->mlx_win, p->img ,p->x + (cos(p->rotation_angle ) * 30),p->y + (sin(p->rotation_angle) * 30) );
        p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->turn_direcrtion = +1;
    }
	else if (keycode == 0)
    {
        mlx_put_image_to_window(p->mlx, p->mlx_win, p->img ,p->x + (cos(p->rotation_angle ) * 30),p->y + (sin(p->rotation_angle) * 30) );
        p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->turn_direcrtion = -1;
    }
	else if (keycode == 1)
    {
        mlx_put_image_to_window(p->mlx, p->mlx_win, p->img ,p->x + (cos(p->rotation_angle ) * 30),p->y + (sin(p->rotation_angle) * 30) );
        p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->walk_direcrtion = -1;
    }
	else if (keycode == 13)
    {
        mlx_put_image_to_window(p->mlx, p->mlx_win, p->img ,p->x + (cos(p->rotation_angle ) * 30),p->y + (sin(p->rotation_angle) * 30) );
        p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->walk_direcrtion = +1; 
    }
	return (0);
}

int	key_relese(int keycode, t_player *p)
{
    if (keycode == 2)
    {
        p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->turn_direcrtion = 0;
    }
	else if (keycode == 0)
    {
    p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->turn_direcrtion = 0;
    }
	else if (keycode == 1)
		{
            p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
            p->walk_direcrtion = 0;
        }
    else if (keycode == 13)
    {
p->rotation_angle += p->turn_direcrtion * p->rotaion_speed;
		p->walk_direcrtion = 0; 
    }
    
	return (0);
}

void palyer_movement(t_m *m, t_player *p)
{
    init_(p);
    mlx_hook(p->mlx_win, 02, 1L<<0, key_hook, p);// relese
	mlx_hook(p->mlx_win, 03, 1L<<1, key_relese, p);
   

}