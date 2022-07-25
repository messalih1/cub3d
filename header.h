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
#define MAP_NUM_ROWS 5
#define MAP_NUM_COLS 23

#define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE
#define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE

#define FOV_ANGLE 60 * (PI / 180)
#define WALL_STRIP_WIDTH 4
#define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH

typedef struct t_struct{
	
    int fd;
    int i;
    int j;
    int x;
    int len;
    char *str;
    char **allocation;
    char **lines;
    
}t_m;

;
 

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
    int x;
    int y;
    int radius;
    int turn_direcrtion;
    int walk_direcrtion;
    double rotation_angle;
    double move_speed;
    double rotaion_speed;

}t_player;




void palyer_movement(t_m *m, t_player *img);
int	line_count(int fd, char *file);
void alloc_lines(t_m *m, char *file);
void put_walls(t_m *m, t_player *img, char *file);
char	*free_tab(char *str, char c);
char	*get_next_line(const int fd);
char	is_newline_endof_str(char c);
char	*ft_realloc(char *ptr, size_t size);
char	get_a_char(int fd);

#endif