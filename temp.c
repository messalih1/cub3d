

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




if first index of line is espace or tab or 1 else is error



111111111111111
100000100000001

3.


= alloc all line of file in block

= if line has espace slice this espace and check next line if has 1 | 0 





    int i = 0;
    char *str = map->allocation[0];
    int t;
    while (str[i])
    {
        if(str[i] == '1')
        {
            t = i;
            i++;
            while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' )
                i++;
            if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
                printf("%s\n",ft_substr(str,t , i - t ));
           
        }
        else if(str[i] == ' ' || str[i] == '\t')
        {
            i++;
            if(str[i] == '\n')
                return 0;
            else
                i--;
        }
        else if(str[i] == '\0')
            break;
        else
            return 0;

        i++;
    }



     
    map->i = 0;
    while (map->allocation[map->i])
    {
        map->j = 0;
        while(map->allocation[map->i][map->j])
        {
            if(map->allocation[map->i][map->j] == '1')
            {
                map->j++;
                while(map->allocation[map->i][map->j])
                {
                    if(map->allocation[map->i][map->j] == ' ' || map->allocation[map->i][map->j] == '\t')
                    {
                        printf("%s\n",&map->allocation[map->i][map->j]);
                        // printf("%s",&map->allocation[map->i][map->j - 3]);
                         
                    }
                    map->j++;
                }
            }
            map->j++;
        }   
        map->i++;
    }
    






    i = 0;
        while (str[i])
        {
            if(str[i] == '1')
            {
                t = i;
                while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' )
                    i++;
                if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
                {
                    str = ft_substr(str,t , i - t );
                    // call_func(str,map->allocation[x]);
                }
                 
            }
            else if(str[i] == ' ' || str[i] == '\t')
            {
                i++;
                if(str[i] == '\n')
                    return 0;
                else
                    i--;
            }
            else if(str[i] == '\0')
                break;
            else
                return 0;
            i++;
        }