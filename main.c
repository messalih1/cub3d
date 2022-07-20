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


int check_map(t_map *map, char *file)
{
    map->i = 0;
 	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
		return (0);
    map->len = line_count(map->fd, file);
	map->fd = open(file, O_RDONLY);
	if (map->fd == -1)
		return (0);
	map->aloc = malloc(sizeof(char *) * map->len + 1);
	if (map->aloc == NULL)
		return (0);
	map->aloc[map->i] = get_next_line(map->fd);

    int i = 0;
    if(map->aloc[map->i][i] == '\n')
        return 0;
    while (map->aloc[map->i][i])
    {
        if(map->aloc[map->i][i] == ' ' || map->aloc[map->i][i] == '\t')
        {
            while (map->aloc[map->i][i] && (map->aloc[map->i][i] == ' ' || map->aloc[map->i][i] == '\t'))
                i++;
            if(ft_strlen(map->aloc[map->i]) - 1 == (int)i)
                return 0;
            else if(map->aloc[map->i][i] != '1' && map->aloc[map->i][i] != '\n')
                return 0;
        }
        else if(map->aloc[map->i][i] == '1')
        {
            while(map->aloc[map->i][i] == '1')
                i++;
            if(map->aloc[map->i][i] != ' ' && map->aloc[map->i][i] != '\t' && map->aloc[map->i][i] != '\n')
                return 0;
        }
        i++;
    }
    return 1;
}



int main(int argc, char *argv[])
{
    t_map	m;
	t_map	*mm;

	mm = &m;
	
	// if (check_map(&m, argv[1]) == 0)
	// {
	// 	printf("error\n");
	// 	return (0);
	// }
   printf("%d\n",check_map(&m, argv[1]));
  
    return 0;
}