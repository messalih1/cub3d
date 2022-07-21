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
    while (m->str[i])
    {
        if(m->str[i] == ' ' || m->str[i] == '\t')
        {
            while (m->str[i] && (m->str[i] == ' ' || m->str[i] == '\t'))
                i++;
            if(ft_strlen(m->str) - 1 == (int)i)
                return 0;
            else if(m->str[i] != '1' && m->str[i] != '\n')
                return 0;
        }
        else if(m->str[i] == '1')
        {
            while(m->str[i] == '1')
                i++;
            if(m->str[i] != ' ' && m->str[i] != '\t' && m->str[i] != '\n')
                return 0;
        }
        i++;
    }
    return (1);
}

int chek_first_line(t_map *map, char *file)
{
    int fd;
 
 	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map->str = get_next_line(fd);
    if(map->str[0] == '\n')
        return (0);
    return (check_first_line_(map, 0));
  
}

