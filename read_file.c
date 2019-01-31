/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:44:14 by fgaujard          #+#    #+#             */
/*   Updated: 2019/01/31 17:54:24 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

/*static int		line_info(int const fd, char **str)
  {
  char	*buff;
  int		ret;

  if (!(buff = (char *)ft_strnew(sizeof(*buff) * 2)))
  return (-1);
  ret = read(fd, buff, 1);
  if (ret > 0)
  {
  buff[ret] = '\0';
 *str = ft_strappend(*str, buff);
 }
 free(buff);
 return (ret);
 }

 int		save_line()
 {
 char *str;
 int ret;

 ret = line_info(fd, str);
 while (ret > 0)
 ret = line_info(fd, str);
 }
 */

char	*read_file(int fd)
{
	char c;
	char *str;
	int oct;

	oct = 0;
	while (read(fd, &c, 1) > 0)
		oct++;
	if (!(str = (char *)ft_strnew(sizeof(str) * (oct + 1))))
		return (NULL);
	oct = 0;
	while (read(fd, &c, 1) > 0)
		str[oct++] = c;
	return (str);
}

int		main(int ac, char **av)
{
	int fd;
	char *str;

	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	ft_putstr(read_file(fd));
	close(fd);
	return (0);
}
