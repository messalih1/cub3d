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
 

void alloc_pixels(t_player *p)
{ 
    int i;
    int fd;

    // i = 0;
    // fd = open("./txt", O_RDONLY);
	 
	// p->pixels = malloc(sizeof(char *) * 134); 
    // while (i < 134)
    // {
	// 	p->pixels[i] = get_next_line(fd);
    //     i++;
    // }
	// p->pixels[i] = NULL;
    // i = 0;
    // size_t len = 0;
    // while (i < 134)
    // {
	// 	len += ft_strlen(p->pixels[i]);
    //     i++;
    // }
    // p->text_px = malloc(sizeof(char) * len);
    // i = 0;
    // int j = 0;
    // int x = 0;
    // while (p->pixels[j])
    // {
    //     x = 0;
    //     while (p->pixels[j][x])
    //     {
    //         p->text_px[i] = p->pixels[j][x];
    //         x++;
    //         i++;
    //     }
        
    //     j++;
    // }

}
