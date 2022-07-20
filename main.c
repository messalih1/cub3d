#include "header.h"



int check_midile_line(t_map *map, char *file)
{
    int len;
    int i;

    i = 0;
    len = map->len;
    map->fd = open(file, O_RDONLY);
    get_next_line(map->fd);
    while (len-- >= 0)
    {
        map->aloc[i] = get_next_line(map->fd);
        i++;
    }
    map->aloc[i] = NULL;
    i = 0;
    while (map->aloc[i])
    {
        printf("%s",map->aloc[i]);
        i++;
    }
 
  
    
    


    return 1;
}


int check_map(t_map *map, char *file)
{
    if(!chek_first_line(map, file))
        return (0);
    if(!check_midile_line(map, file))
        return (0);
    return 1;
}

int main(int argc, char *argv[])
{
    t_map	m;
	t_map	*mm;

	mm = &m;
	
	if (check_map(&m, argv[1]) == 0)
	{
		printf("error\n");
		return (0);
	}
    
  
    return 0;
}