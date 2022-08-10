#ifndef HEADER_H
#define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
#include "libft/libft.h"
#include <math.h>

#define PI 3.14159265358979323846

#define BUFFER_SIZE 1
#define TILE_SIZE 40
#define MAP_NUM_ROWS 12
#define MAP_NUM_COLS 25

#define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE
#define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE

#define FOV_ANGLE 60 * (PI / 180)
#define WALL_STRIP_WIDTH 4
#define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

#define MINIMAP_SCALE_FACTOR 0.2

typedef struct t_struct{
	
    int fd;
    int i;
    int j;
    int x;
    int len;
    char *str;
    
    
}t_m;
 
typedef struct t_t{
	
    int        wall_hit_x;
    int        wall_hit_y;
    float     h_wall_hit_x;
    float     h_wall_hit_y;
    float     h_next_hor_x;
    float     h_next_hor_y;
    float     h_xintercept;
    float     h_yintercept;
    float     h_xstep;
    float     h_ystep;
    int     h_found_wall;

    float     v_wall_hit_x;
    float     v_wall_hit_y;
    float     v_next_vir_x;
    float     v_next_vir_y;
    float     v_xintercept;
    float     v_yintercept;
    float     v_xstep;
    float     v_ystep;
    int     v_found_wall;
    float     distance;
}t_find;
 
 

typedef struct t_play
{
    void	    *mlx;
	void	*mlx_win;
	void	*walls;
	char	*p_walls;
    void	*img_black;
    char	*p_img_black;
	void	*img_circle;
	char	*p_img_circle;
	void	*img_red_line;
	void	*img_black_line;
	char	*p_img_black_line;
	char	*p_img_red_line;
    int		bits_per_pixel;
	int		line_length;
	int		endian;
    float     ray_angle;
    float     x;
    float     y;
    double rotation_angle;
    double rotaion_speed;
    int turn;
    int walk;
    char **lines;
    
    t_m map;
    t_find find;

}t_player;

void ddadraw(float x,float y,float x1,float y1,t_player *t);
int point_in_range(float x, float y);
void vertical_intersection(t_player *p);
void horizontal_intersection(t_player *p);
void cast_ray(t_player *p);
void palyer_movement(t_m *m, t_player *img);
int	line_count(int fd, char *file);
char** alloc_lines(t_player *m, char *file);
void put_walls(t_m *m, t_player *img, char *file);
char	*free_tab(char *str, char c);
char	*get_next_line(const int fd);
char	is_newline_endof_str(char c);
char	*ft_realloc(char *ptr, size_t size);
char	get_a_char(int fd);

#endif