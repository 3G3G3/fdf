#include "fdf.h"

int			main(int argc, char **argv)
{
	t_list		*points;
	if (argc != 2)
		return (-1);
	points = ft_readfile(argv[1]);
	while (points)
	{
		ft_putendl(points->content);
		points = points->next;
	}
	return (1);
}
