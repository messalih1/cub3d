#ifndef HEADER_H
#define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
#include "libft/libft.h"
#define BUFFER_SIZE 1
typedef struct check_map{
	
    int fd;
    int i;
    int j;
    int x;
    int len;
    char *str;
    char **allocation;
    char **lines;
    


}t_map;


int check(t_map *map);
int alloc_lines(t_map *map, char *file);
int check_midile_line(t_map *map, char *file);
int chek_first_line(t_map *map, char *file);
int check_map(t_map *map, char *file);
int	line_count(int fd, char *file);
char	*free_tab(char *str, char c);
char	*get_next_line(const int fd);
char	is_newline_endof_str(char c);
char	*ft_realloc(char *ptr, size_t size);
char	get_a_char(int fd);

#endif