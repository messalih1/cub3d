#include "header.h"

//   turn_direcrtion -1 if left , +1 if rihgt
//   walk_direcrtion -1 if back, +1 if front
// moves_peed  fast of moving player pixel per freme
// rotarion_speed pi / 180 => 0.001 * 3 rotaion => 3 degre  



void inti_player(t_m *m, t_player *p)
{
  p->x = WINDOW_WIDTH / 2;
  p->y = WINDOW_HEIGHT / 2;
  
  p->rotation_angle = PI / 2;
   
	p->p_img_circle = "./Shape-1.xpm";
	p->img_circle =  mlx_xpm_file_to_image(p->mlx, p->p_img_circle, &p->line_length, &p->endian);
	mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_circle ,p->x , p->y  ); 
}

int	key_hook(int keycode, t_player *p)
{
  if (keycode == 13)// w
  {
   
    p->x += cos(p->rotation_angle) * 2; // if up inciment the space by cos angle
    p->y -= sin(p->rotation_angle) * 2;       // if up decrment the space by cos angle
    mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_circle, p->x  ,p->y  );
  }
	else if (keycode == 1)//s
  {
     // if down decrament by the space to you increment leter
    p->x -= cos(p->rotation_angle) * 2; 
    p->y += sin(p->rotation_angle) * 2;       
    mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_circle, p->x  , p->y );
  }
  else if (keycode == 124)
  {
    p->rotation_angle -=  PI / 3;
    if(p->rotation_angle <= 0 )
      p->rotation_angle += 2 * PI;
  }
  else if (keycode == 123)
  {
     p->rotation_angle +=  PI / 3;
    if(p->rotation_angle >= 2 * PI)
      p->rotation_angle -= 2 * PI;
  }
    

  // printf("%f\n",p->rotation_angle);
	cast_ray(p);
	return (0);
}

 
void palyer_movement(t_m *m, t_player *p)
{
  inti_player(m,p);
  mlx_hook(p->mlx_win, 02, 1L<<0, key_hook, p);
 
} 