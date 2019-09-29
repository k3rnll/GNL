/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:00:26 by tmarkita          #+#    #+#             */
/*   Updated: 2019/09/29 17:22:14 by tmarkita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

static int	end_line(char **tmp)
{
	int		i;
	char	*t_tmp;

	t_tmp = *tmp;
	i = 0;
	while ((*tmp)[i] != '\0')
	{
		if ((*tmp)[i] == '\n')
		{
			*tmp = ft_strsub((const char *)*tmp, 0, i);
			ft_strdel(&t_tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_realloc(char **s, unsigned int start)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(*s) - start;
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = (*s)[start];
		i++;
		start++;
	}
	str[i] = '\0';
	ft_strdel(s);
	return (str);
}

static int	new_line(char **buf_tmp, char **new, char **line)
{
	char	*tmp;
	char	*t_new;

	t_new = *new;
	tmp = ft_strsub(*buf_tmp, 0, ft_strlen(*buf_tmp));
	if (end_line(&tmp))
	{
		*buf_tmp = ft_realloc(buf_tmp, ft_strlen(tmp) + 1);
		*new = ft_strjoin(*new, tmp);
		*line = *new;
		ft_strdel(&t_new);
		ft_strdel(&tmp);
		return (1);
	}
	*new = ft_strjoin(*new, tmp);
	ft_strdel(&t_new);
	ft_strdel(&tmp);
	return (0);
}

static int	last_line(char **buf_tmp, char **new, char **line)
{
	if (!**new)
		return (0);
	ft_strdel(buf_tmp);
	*line = *new;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE];
	static char		*buf_tmp[10];
	int				ret;
	char			*new;

	if (fd < 0)
		return (-1);
	new = ft_strnew(0);
	if (buf_tmp[fd])
	{
		if (new_line(&buf_tmp[fd], &new, line))
			return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_strdel(&buf_tmp[fd]);
		buf_tmp[fd] = ft_strsub(buf, 0, ret);
		if (new_line(&buf_tmp[fd], &new, line))
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (last_line(&buf_tmp[fd], &new, line))
		return (1);
	return (0);
}
