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
    char **aloc;
    


}t_map;
char	*free_tab(char *str, char c);
char	*get_next_line(const int fd);
char	is_newline_endof_str(char c);
char	*ft_realloc(char *ptr, size_t size);
char	get_a_char(int fd);

#endif