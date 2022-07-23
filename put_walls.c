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

void alloc_lines(t_m *m, char *file)
{
    int len;
    int i;
    int fd;

    i = 0;
    fd = open(file, O_RDONLY);
    len = line_count(fd,file);
	m->len = len;
    m->allocation = malloc(sizeof(char*) * len + 1);
    fd = open(file, O_RDONLY);
    while (i < len)
    {
        m->allocation[i] = get_next_line(fd);
        i++;
    }
    m->allocation[i] = NULL;
}



void put_walls(t_m *m, t_data *img, char *file)
{
	alloc_lines(m, file);
	img->img_path = "./wall.xpm";
	img->img_path_ = "./black.xpm";
	
	img->img =  mlx_xpm_file_to_image(img->mlx, img->img_path, &img->line_length, &img->endian);
	img->img_ =  mlx_xpm_file_to_image(img->mlx, img->img_path_, &img->line_length, &img->endian);
 

	int i = 0;
	int x;
	int j;
	int z;
	
	z = 0;
		j = 0;
	while (i < m->len)
	{
		x = 0;
		j = 0;
		while (m->allocation[i][x] != '\n')
		{
			if(m->allocation[i][x] == '1')
			{
				mlx_put_image_to_window(img->mlx, img->mlx_win,img->img ,j, z);
				j+= TILE_SIZE;
			}
			else
			{
				mlx_put_image_to_window(img->mlx, img->mlx_win,img->img_ ,j, z);
				j+= TILE_SIZE;
			}	
			x++;
		}
		z += TILE_SIZE;
		i++;
	}
	




}

