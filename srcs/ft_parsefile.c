/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:49:25 by grgauthi          #+#    #+#             */
/*   Updated: 2019/05/04 17:35:47 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_list			*ft_parsepoint(char *point)
{
	t_list		*res;
	return (res);
}
*/

t_list			*ft_parseline(char *line)
{
	t_list		*res;

	res = ft_lstnew(line, ft_strlen(line) + 1);
	free(line);
	return (res);
}

t_list			*ft_parsefile(const int fd)
{
	char		*line;
	t_list		*tmp;
	t_list		*res;

	if (get_next_line(fd, &line) > 0)
	{
		res = ft_parseline(line);
		if (res == NULL)
			return (NULL);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if ((tmp = ft_parseline(line)) == NULL)
			return (NULL);
//		free list;
		ft_lstadd_fifo(&res, tmp);
	}
	return (res);
}

t_list			*ft_readfile(char *filename)
{
	int			fd;
	t_list		*res;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	res = ft_parsefile(fd);
	close(fd);
	return (res);
}

