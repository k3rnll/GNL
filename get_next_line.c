/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:00:26 by tmarkita          #+#    #+#             */
/*   Updated: 2019/09/23 15:45:44 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	BUFF_SIZE 32

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE];
	char	*tmp;

	tmp = ft_strnew(0);
	while (ret = read(fd, buf, BUFF_SIZE))
		while (buf:
		tmp = ft_strjoin(tmp, buf);


