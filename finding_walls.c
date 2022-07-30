#include "header.h"



void normaliz_angle(t_player *p)// keep ray between 0 and 360 (0 && 2pi)
{
    int x;
    int t;
        // ray facing
    t = p->ray_angle;
    x = (2 * PI );
    p->ray_angle = p->ray_angle % x; // if x > 0 x will still the same value
    if(p->ray_angle < 0)
        p->ray_angle = (2 * PI) + p->ray_angle; // add 2pi to be positive
  
}

void cast_ray(int id, t_player *p)
{
    int xintercept;
    int yintercept;
    int xstep;
    int ystep;

    yintercept = (int)(p->y / TILE_SIZE) * TILE_SIZE;
    xintercept = p->x + (yintercept - p->y_intercept) / tan(p->ray_angle);


}

void fiew_of_view(t_player *p)
{
	int ray_id;
	int i;

	ray_id = 0;
    //              pi / 2  90 - 60 / 2   
	p->ray_angle = p->rotation_angle - (FOV_ANGLE / 2);// you can alloc by number of rays and assign the values by indexws to access
	i = 0;
	while (i < 1)
	{
		p->ray_angle += FOV_ANGLE / NUM_RAYS;
		cast_ray(ray_id, p);
        ray_id++;// is the ray_Id
		i++;
	}
    normaliz_angle(p);// by this func we confined ray between 6 time (360 / 60), and ignor be negative
        // printf("%d\n",colum_id);
    // will be round by 1 pi
    // if not create this fuc will round gretan than 1 pi or less than 1 pi 
    // p->ray_angle he round 6 time at the circle 
    // printf("%d\n",p->ray_angle); 
	 
}


//  Math.floor convert to int