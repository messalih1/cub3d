#include "header.h"








int check_map(t_map *map, char *file)
{
    if(alloc_lines(map,file))
        return check_midile_line(map, file);

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