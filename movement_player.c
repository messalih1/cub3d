#include "header.h"

//   turn_direcrtion -1 if left , +1 if rihgt
//   walk_direcrtion -1 if back, +1 if front
// moves_peed  fast of moving player pixel per freme
// rotarion_speed pi / 180 => 0.001 * 3 rotaion => 3 degre  



void inti_player(t_m *m, t_player *p)
{
    p->x = WINDOW_WIDTH / 2;
    p->y = WINDOW_HEIGHT / 2;
    p->radius = 3;
    p->turn_direcrtion = 0;
    p->walk_direcrtion = 0;
    p->rotation_angle = PI / 2;
    p->move_speed = 2.0; 
    p->rotaion_speed = 2 * (PI / 180);
	p->p_img_circle = "./circle.xpm";
	p->img_circle =  mlx_xpm_file_to_image(p->mlx, p->p_img_circle, &p->line_length, &p->endian);
	mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_circle ,p->x, p->y);
	p->p_img_red_line = "./line.xpm";
	p->img_red_line =  mlx_xpm_file_to_image(p->mlx, p->p_img_red_line, &p->line_length, &p->endian);
	mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_red_line ,p->x + (cos(p->rotation_angle ) * 10 ),p->y + (sin(p->rotation_angle)) * 10);
}



int	key_hook(int keycode, t_player *p)
{
    if (keycode == 2)
    {
        p->turn_direcrtion = -1; 
        p->rotation_angle += p->turn_direcrtion + p->rotaion_speed;
	    // mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_red_line ,p->x + (cos(p->rotation_angle ) * 10 ), p->y + (sin(p->rotation_angle)) * 10);

    }
	else if (keycode == 0)
    {
		p->turn_direcrtion = +1; 
        p->rotation_angle += p->turn_direcrtion + p->rotaion_speed;
	    // mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_red_line ,p->x + (cos(p->rotation_angle ) * 10 ), p->y + (sin(p->rotation_angle)) * 10);

    }
	else if (keycode == 1)
    {
		p->walk_direcrtion = +1; 
        int move_step = p->walk_direcrtion * p->move_speed;
        p->x += cos(p->rotation_angle) * move_step; 
        p->y += sin(p->rotation_angle) * move_step; 
	    mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_circle ,p->x  , p->y  );
    
    }
	else if (keycode == 13)
    {
		p->walk_direcrtion = -1;  
        int move_step = p->walk_direcrtion * p->move_speed;
        p->x += cos(p->rotation_angle) * move_step; 
        p->y += sin(p->rotation_angle) * move_step; 
	    mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_circle ,p->x  , p->y  );
    }
    else if (keycode == 124)
    {
		p->turn_direcrtion = -1; 
        p->rotation_angle += p->turn_direcrtion + p->rotaion_speed;
	    // mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_red_line ,p->x + (cos(p->rotation_angle ) * 10 ), p->y + (sin(p->rotation_angle)) * 10);

    }
    else if (keycode == 123)
    {
		p->turn_direcrtion = +1; 
        p->rotation_angle += p->turn_direcrtion + p->rotaion_speed;
	    // mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_red_line ,p->x + (cos(p->rotation_angle ) * 10 ),p->y + (sin(p->rotation_angle)) * 10 );

    }
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
    else if (keycode == 123)
		p->turn_direcrtion = 0; 
    else if (keycode == 124)
		p->turn_direcrtion = 0; 
     
	return (0);
}
void palyer_movement(t_m *m, t_player *p)
{
    inti_player(m,p);
    mlx_hook(p->mlx_win, 02, 1L<<0, key_hook, p);
	mlx_hook(p->mlx_win, 03, 1L<<1, key_relese, p);// relese



} 