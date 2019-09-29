/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 09:19:06 by tmarkita          #+#    #+#             */
/*   Updated: 2019/09/29 16:03:14 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft.h"
#include "stdio.h"

int		get_next_line(const int fd, char **line);

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		fd2;

	fd = open(av[1], O_RDONLY);
//	fd2 = open(av[2], O_RDONLY);
	
	line = ft_strnew(100);
	get_next_line(fd, &line);
	printf("%s\n", line);
	ft_strdel(&line);

	get_next_line(fd, &line);
	printf("%s\n", line);

	ft_strdel(&line);
	get_next_line(fd, &line);
	printf("%s\n", line);

	ft_strdel(&line);
	close(fd);
}
