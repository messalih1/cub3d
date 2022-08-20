#include "../includes/header.h"


static int	line_count(int fd)
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

static char **alloc_lines(t_player *p)
{
    int len;
    int i;
    int fd;

    i = 0;
    fd = open(p->map.file, O_RDONLY);
    len = line_count(fd);
	p->map.len = len;
    char **allocation = malloc(sizeof(char*) * len + 1);
    fd = open(p->map.file, O_RDONLY);
    while (i < len)
    {
        allocation[i] = get_next_line(fd);
        i++;
    }
    allocation[i] = NULL;
	return  allocation;
}



int put_walls(t_player *p)
{
	char **alloc = alloc_lines(p);
	p->p_walls = "./images/wall.xpm";
	p->p_img_black = "./images/black.xpm";
	
	p->walls =  mlx_xpm_file_to_image(p->mlx, p->p_walls, &p->line_length, &p->endian);
	p->img_black =  mlx_xpm_file_to_image(p->mlx, p->p_img_black, &p->line_length, &p->endian);
	 
 	 
	int i = 0;
	int x;
	int j;
	int z;
	
	z = 0;
	j = 0;
	while (i < p->map.len)
	{
		x = 0;
		j = 0;
		while (alloc[i][x] != '\n')
		{
			if(alloc[i][x] == '1')
			{
				mlx_put_image_to_window(p->mlx, p->mlx_win,p->walls ,j , z);
				j+= TILE_SIZE;
			}
			else
			{
				mlx_put_image_to_window(p->mlx, p->mlx_win,p->img_black ,j,z);
				j+= TILE_SIZE;
			}	
			x++;
		}
		z += TILE_SIZE;
		i++;
	}
	p->lines = alloc;
	return(1);
}

 