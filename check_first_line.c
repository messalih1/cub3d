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

static int check_first_line_(t_map *m, int i)
{
    while (m->aloc[m->i][i])
    {
        if(m->aloc[m->i][i] == ' ' || m->aloc[m->i][i] == '\t')
        {
            while (m->aloc[m->i][i] && (m->aloc[m->i][i] == ' ' || m->aloc[m->i][i] == '\t'))
                i++;
            if(ft_strlen(m->aloc[m->i]) - 1 == (int)i)
                return 0;
            else if(m->aloc[m->i][i] != '1' && m->aloc[m->i][i] != '\n')
                return 0;
        }
        else if(m->aloc[m->i][i] == '1')
        {
            while(m->aloc[m->i][i] == '1')
                i++;
            if(m->aloc[m->i][i] != ' ' && m->aloc[m->i][i] != '\t' && m->aloc[m->i][i] != '\n')
                return 0;
        }
        i++;
    }
    return (1);
}

int chek_first_line(t_map *map, char *file)
{
    map->i = 0;
 	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
		return (0);
    map->len = line_count(map->fd, file);
	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
		return (0);
	map->aloc = malloc(sizeof(char *) * map->len);
	if (map->aloc == NULL)
		return (0);
	map->aloc[map->i] = get_next_line(map->fd);
    if(map->aloc[map->i][0] == '\n')
        return (0);
    return (check_first_line_(map, 0));
}

