#include "../includes/header.h"


int	line_count(int fd)
{
	char	*str;
	int		x;

	x = 0;
	str = get_next_line(fd);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		x++;
	}
	free(str);
	close(fd);
	return (x);
}

void alloc_lines(t_player *p)
{
    int len;
    int i;
    int fd;

    i = 0;
    fd = open(p->map.file, O_RDONLY);
    len = line_count(fd);
	p->map.len = len;
    p->lines = malloc(sizeof(char*) * len + 1);
    fd = open(p->map.file, O_RDONLY);
    while (i < len)
    {
        p->lines[i] = get_next_line(fd);
        i++;
    }
    p->lines[i] = NULL;
 
}
  