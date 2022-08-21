#ifndef HEADER_H
#define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
#include "../libft/libft.h"
#include <math.h> 

#define PI 3.14159265358979323846
#define BUFFER_SIZE 1

#define TILE_SIZE 40

#define MAP_NUM_ROWS 14
#define MAP_NUM_COLS 33

#define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE
#define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE
 
#define WALL_STRIP_WIDTH 4
 

 
typedef struct t_struct{
	
    char *file;
    int fd;
    int i;
    int j;
    int x;
    int len;
    char *str;
}t_m;
 
typedef struct t_h{

    double        wall_hit_x;
    double        wall_hit_y;
    double       next_x;
    double       next_y;
    double     x_intercept;
    double     y_intercept;
    double     x_step;
    double     y_step;
    int         found_wall;
    double     *distance;
    int i;
}t_hor;

typedef struct t_v{
    double        wall_hit_y;
    double     wall_hit_x;
    double       next_x;
    double       next_y;
    double     x_intercept;
    double     y_intercept;
    double     x_step;
    double     y_step;
    int         found_wall;
    double     *distance;
    int i;

}t_ver;
 

typedef struct t_play
{
    void    *img;
    char	*addr;
    void	 *mlx;
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
    double     ray_angle;
    double     x;
    double     y;
    double rotation_angle;
    double turn_speed;
    int turn;
    int walk;
    int walk_speed;
    char **lines;
    double     *distance;
    int     num_of_rays;
    double fov_angle;
    t_m map;
    t_hor hor;
    t_ver ver;
}t_player;

void rendering_walls(t_player *p);
double  distance_calc(double x1,double y1,double x2,double y2);
void vertical_intersections(t_player *p);
void drawDDA(int xA,int yA,int xB,int yB,t_player *game);
void horizontal_intersections(t_player *p);
int point_in_range(float x, float y);
void DDA(int X0, int Y0, int X1, int Y1,t_player *p);
void find_intersections(t_player *p);
void put_player(t_player *p);
int     put_walls(t_player *p);
int    moves_of_player(t_player *p);
char	*free_tab(char *str, char c);
char	*get_next_line(const int fd);
char	is_newline_endof_str(char c);
char	*ft_realloc(char *ptr, size_t size);
char	get_a_char(int fd);

#endif