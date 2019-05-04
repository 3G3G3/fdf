/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:46:26 by grgauthi          #+#    #+#             */
/*   Updated: 2018/12/18 15:14:40 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_readchr(const int fd, int c)
{
	char	*buf;
	char	*line;
	int		rnull;

	rnull = 0;
	buf = ft_strnew(BUFF_SIZE);
	line = ft_strnew(BUFF_SIZE);
	if (!line || !buf)
		rnull = 1;
	if (rnull == 0 && read(fd, line, BUFF_SIZE) < 0)
		rnull = 1;
	while (rnull == 0 && read(fd, buf, BUFF_SIZE) > 0)
	{
		line = ft_strjoinfree(line, buf);
		if (!line)
			rnull = 1;
		if (ft_strchr(buf, c) != NULL)
			break ;
		buf = ft_memset(buf, '\0', BUFF_SIZE + 1);
	}
	if (rnull == 1)
		ft_strdel(&line);
	ft_strdel(&buf);
	return (line);
}

static char		*ft_initremainder(char *str)
{
	char		*tmp;

	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n') == NULL)
	{
		ft_strdel(&str);
		return (NULL);
	}
	tmp = str;
	str = ft_strdup(ft_strchr(str, '\n') + 1);
	ft_strdel(&tmp);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (str);
}

static int		ft_addremainder(const int fd, char **remainder)
{
	char	*n_remainder;
	char	*tmp;

	if (!remainder || !*remainder)
		n_remainder = ft_readchr(fd, '\n');
	else
	{
		tmp = ft_readchr(fd, '\n');
		n_remainder = ft_strjoin(*remainder, tmp);
		ft_strdel(&tmp);
	}
	if (!n_remainder)
		return (-1);
	tmp = *remainder;
	if (n_remainder[0] == '\0')
	{
		ft_strdel(&n_remainder);
		return (0);
	}
	else
		*remainder = n_remainder;
	ft_strdel(&tmp);
	return (1);
}

static int		ft_readremainder(t_list **remainder_lst,
												char **remainder, const int fd)
{
	t_list		*tmp;

	if (*remainder_lst == NULL || ft_lstiscs(*remainder_lst, fd) == 0)
	{
		if ((tmp = ft_lstnew(NULL, 0)) == NULL)
			return (-1);
		tmp->content_size = fd;
		ft_lstadd_fifo(remainder_lst, tmp);
	}
	if (*remainder_lst == NULL)
		return (-1);
	*remainder = ft_lstfindone(*remainder_lst, fd, &ft_lstiscs)->content;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int					res;
	char				*remainder;
	static t_list		*remainder_lst = NULL;

	res = 1;
	if (ft_readremainder(&remainder_lst, &remainder, fd) == -1)
		return (-1);
	remainder = ft_lstfindone(remainder_lst, fd, &ft_lstiscs)->content;
	if (remainder == NULL || ft_strchr(remainder, '\n') == NULL)
		res = ft_addremainder(fd, &remainder);
	if (res > 0)
	{
		*line = ft_strsub(remainder, 0, ft_strchri(remainder, '\n'));
		if (!(*line))
			return (-1);
		remainder = ft_initremainder(remainder);
	}
	if (res > 0)
		ft_lstfindone(remainder_lst, fd, &ft_lstiscs)->content = remainder;
	return (res);
}
