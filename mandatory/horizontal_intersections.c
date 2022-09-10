/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:50:08 by tnamir            #+#    #+#             */
/*   Updated: 2022/09/10 19:20:04 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void init_hor(t_player *p, int if_is_facing_up)
{
    p->hor.next_x = p->hor.x_intercept;
	p->hor.next_y = p->hor.y_intercept;
	if (if_is_facing_up)
		p->hor.next_y--;
	p->hor.found_wall = 0;
}

void	wall_intersect_horizontal(t_player *p, int if_is_facing_up)
{
	init_hor(p, if_is_facing_up);
	while (point_in_range(p->hor.next_x, p->hor.next_y, p))
	{
		if (p->cub_info.map[(int)(p->hor.next_y / TILE_SIZE)]
		[(int)(p->hor.next_x / TILE_SIZE)] == '1')
		{
			p->hor.found_wall = 1;
			p->hor.wall_hit_y = p->hor.next_y;
			p->hor.wall_hit_x = p->hor.next_x;
			break;
		}
		else
		{
			p->hor.next_y += p->hor.y_step;
			p->hor.next_x += p->hor.x_step;
		}
	}
    if((p->hor.found_wall))
        p->hor.distance[p->hor.i] =  distance_calc(p->x,p->y,p->hor.next_x,p->hor.next_y);
    else
        p->hor.distance[p->hor.i] =  10000000.444;
	p->hor.i++;

}

void horizontal_intersections_(t_player *p, int left, int right, int facing_up)
{
    if (left && p->hor.x_step > 0)
        p->hor.x_step *= -1;
    else
        p->hor.x_step *= 1;
    if (right && p->hor.x_step < 0)
        p->hor.x_step *= -1;
    else
        p->hor.x_step *= 1;
	wall_intersect_horizontal(p,facing_up);
    
}
void horizontal_intersections(t_player *p)
{
	int if_is_facing_up;
	int if_is_facing_down;
	int if_is_facing_right;
	int if_is_facing_left;

	if_is_facing_down = (p->ray_angle > 0 &&  p->ray_angle < PI);
	if_is_facing_up = !if_is_facing_down;
	if_is_facing_right = (p->ray_angle < PI / 2 || p->ray_angle > (3 * PI) / 2);
	if_is_facing_left = !if_is_facing_right;
	p->hor.y_intercept = ((int)(p->y / TILE_SIZE)) * TILE_SIZE;
	if(if_is_facing_down)
		p->hor.y_intercept += TILE_SIZE;
	p->hor.x_intercept = p->x + ((p->hor.y_intercept - p->y) / tan(p->ray_angle)); 
	p->hor.y_step = TILE_SIZE;
    if(if_is_facing_up)
        p->hor.y_step *= -1;
    else
        p->hor.y_step *= 1;
	p->hor.x_step = TILE_SIZE / tan(p->ray_angle);
    horizontal_intersections_(p, if_is_facing_left, if_is_facing_right, if_is_facing_up);
}