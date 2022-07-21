#include "header.h"

 

int alloc_lines(t_map *map, char *file)
{
    int len;
    int i;
    int fd;

    i = 0;
    fd = open(file, O_RDONLY);
    len = line_count(fd,file);
    if(len < 3)
        return 0;
    map->allocation = malloc(sizeof(char*) * len + 1);
    fd = open(file, O_RDONLY);
    while (i < len)
    {
        map->allocation[i] = get_next_line(fd);
        i++;
    }
    map->allocation[i] = NULL;
    return 1;
}


int check_vide(t_map *map)
{
    int x;

    x = 0;
    while (map->allocation[x])
    {
        if(map->allocation[x][0] == ' ' || map->allocation[x][0] == '\t' || map->allocation[x][0] == '\n')
        {
            map->i = 0;
            while(map->allocation[x][map->i] 
                && (map->allocation[x][map->i] == ' ' || map->allocation[x][map->i] == '\t'
                    || map->allocation[x][0] == '\n'))
                map->i++;
            if(map->allocation[x][map->i] != '1')
                return 0;
        }
        else if(map->allocation[x][0] != '1')
            return 0;
        x++;
    }
    return 1;
} 

 
int check_(t_map *map)
{
    int x;

    x = 1;
    // while (map->allocation[x])
    // {

        map->i = 1;
        if(map->allocation[x - 1][map->i] == '0' && map->allocation[x][map->i + 1] == '0' && map->allocation[x + 1][map->i] == '0' && map->allocation[x + 2][map->i] == '0')
            printf("YESSSS\n");



    //     x++;
    // }


    return 1;
}


int check_midile_line(t_map *map, char *file)
{
    if(!check_vide(map))
        return 0;
    if(!check_(map))
        return 0;


    return 1;
}