/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsefile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grgauthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:49:25 by grgauthi          #+#    #+#             */
/*   Updated: 2019/07/16 14:42:21 by grgauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			*ft_free_parse(char *line, t_list *lst, char **tab)
{
	if (line != NULL)
		ft_free_char(line);
	if (lst != NULL)
		ft_free_lst(lst);
	if (tab != NULL)
		ft_free_char_2stars(tab);
	return (NULL);
}

t_list			*ft_parsepoint(char *point, int i, int j)
{
	t_point		*res_point;
	t_list		*res_lst;
	char		*str;

	if (ft_strcmp(str = ft_itoa(ft_atoi(point)), point) != 0)
	{
		free(str);
		return (NULL);
	}
	free(str);
	res_point = (t_point *)ft_memalloc(sizeof(t_point));
	if (res_point == NULL)
		return (NULL);
	res_point->x = i;
	res_point->y = j;
	res_point->z = ft_atoi(point);
	res_lst = ft_lstnew(res_point, sizeof(t_point));
	free(res_point);
	return (res_lst);
}

t_list			*ft_parseline(char *line, int j)
{
	t_list		*tmp;
	char		**tmp_split;
	int			i;
	t_list		*res;

	if ((tmp_split = ft_strsplit(line, ' ')) == NULL)
		return ((t_list *)ft_free_parse(line, NULL, NULL));
	if (tmp_split[0] && (res = ft_parsepoint(tmp_split[0], 0, j)) == NULL)
		return ((t_list *)ft_free_parse(line, NULL, tmp_split));
	i = 1;
	while (tmp_split[i])
	{
		if ((tmp = ft_parsepoint(tmp_split[i], i, j)) == NULL)
			return ((t_list *)ft_free_parse(line, res, tmp_split));
		ft_lstadd_fifo(&res, tmp);
		i++;
	}
	ft_free_parse(line, NULL, tmp_split);
	return (res);
}

t_list			*ft_parsefile(const int fd)
{
	char		*line;
	t_list		*tmp;
	int			j;
	t_list		*res;

	res = NULL;
	if (get_next_line(fd, &line) > 0)
	{
		res = ft_parseline(line, 0);
		if (res == NULL)
			return (NULL);
	}
	j = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if ((tmp = ft_parseline(line, j)) == NULL)
		{
			ft_free_lst(res);
			return (NULL);
		}
		ft_set_neighbours(res, j, tmp);
		ft_lstadd_fifo(&res, tmp);
		j++;
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
