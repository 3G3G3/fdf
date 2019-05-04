#include "fdf.h"

t_list			*ft_parsepoint(char *point)
{

}

t_list			*ft_parseline(char *line)
{

}

t_list			*ft_parsefile(const int fd)
{
	char		*line;
	t_list		*res;

	while (get_next_line(fd, &line) > 0)
		ft_lstadd_fifo(&res, ft_parseline(line));
}

t_list			ft_readfile(char *filename)
{
	int			fd;
	t_list		*res;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	res = ft_parsefile(fd);
	close(fd);
	return (res);
}

