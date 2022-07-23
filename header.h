#ifndef HEADER_H
#define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
#include "libft/libft.h"

#define BUFFER_SIZE 1
#define TILE_SIZE 40
#define MAP_NUM_ROWS 5
#define MAP_NUM_COLS 23

#define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE
#define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE


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


typedef struct	s_data {
    void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img_;
	char	*addr;
	char    *img_path;
	char    *img_path_;
    int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	line_count(int fd, char *file);
void alloc_lines(t_m *m, char *file);
void put_walls(t_m *m, t_data *img, char *file);
char	*free_tab(char *str, char c);
char	*get_next_line(const int fd);
char	is_newline_endof_str(char c);
char	*ft_realloc(char *ptr, size_t size);
char	get_a_char(int fd);

#endif