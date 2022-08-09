#include "header.h"


int	line_count(int fd, char *file)
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

char **alloc_lines(t_player *img, char *file)
{
    int len;
    int i;
    int fd;

    i = 0;
    fd = open(file, O_RDONLY);
    len = line_count(fd,file);
	img->map.len = len;
    char **allocation = malloc(sizeof(char*) * len + 1);
    fd = open(file, O_RDONLY);
    while (i < len)
    {
         allocation[i] = get_next_line(fd);
        i++;
    }
     allocation[i] = NULL;
	return  allocation;
}



void put_walls(t_m *m, t_player *img, char *file)
{
	char **alloc = alloc_lines(img, file);
	img->p_walls = "./wall.xpm";
	img->p_img_black = "./black.xpm";
	
	img->walls =  mlx_xpm_file_to_image(img->mlx, img->p_walls, &img->line_length, &img->endian);
	img->img_black =  mlx_xpm_file_to_image(img->mlx, img->p_img_black, &img->line_length, &img->endian);
 

	int i = 0;
	int x;
	int j;
	int z;
	
	z = 0;
	j = 0;
	while (i < img->map.len)
	{
		x = 0;
		j = 0;
		while (alloc[i][x] != '\n')
		{
			if(alloc[i][x] == '1')
			{
				mlx_put_image_to_window(img->mlx, img->mlx_win,img->walls ,j, z);
				j+= TILE_SIZE;
			}
			else
			{
				mlx_put_image_to_window(img->mlx, img->mlx_win,img->img_black ,j, z);
				j+= TILE_SIZE;
			}	
			x++;
		}
		z += TILE_SIZE;
		i++;
	}
	img->lines = alloc;
}

