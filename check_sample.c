#include "fillit.h"

static int		count_tetri(char *str)
{
	int len;
	int size;

	len = ft_strlen(str);
	if (len % 21 != 0)
		return (0);
	size = (len / 21 ) + 1;
	return(size);
}

char	**malloc_tetri(char *str)
{
	int size;
	int i;
	char **tetri;
	char *test;

	size = count_tetri(str);
	if (!(tetri = (char **)ft_strnew(sizeof(char) * size)))
		return(NULL);
	tetri[size] = 0;
	return (tetri);
}
/*
char	*check_tetri(char *str)
{
	int i;
	char **tetri;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != '\0')
			{
				if (str[i] == '.')
					i++;
				else if (str[i] == '#')
				{
				}
				else
					return (0);
			}
		}
	}
	return (tetri);
}
*/
