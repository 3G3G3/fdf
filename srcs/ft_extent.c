#include "fdf.h"

t_point				*ft_get_extent_init(t_point *point)
{
	t_point			*extent;

	extent = (t_point *)ft_memalloc(sizeof(t_point));
	if (extent == NULL)
		return (NULL);
	extent->x_m = point->x_p;
	extent->x_p = point->x_p;
	extent->z_m = point->z_p;
	extent->z_p = point->z_p;
	return (extent);
}

void				ft_get_extent_point(t_point *extent, t_point *point)
{
	extent->x_m = fmin(extent->x_m, point->x_p);
	extent->x_p = fmax(extent->x_p, point->x_p);
	extent->z_m = fmin(extent->z_m, point->z_p);
	extent->z_p = fmax(extent->z_p, point->z_p);
}

void				ft_get_extent(t_list *param)
{
	t_point		*extent;
	t_list		*points;

	points = ft_get_points(param);
	extent = ft_get_extent_init((t_point *)(points->content));
	if (extent == NULL)
		return ;
	points = points->next;
	while (points != NULL)
	{
		ft_get_extent_point(extent, (t_point *)(points->content));
		points = points->next;
	}
	ft_get_move(param)->zoom = fmax(fabs(extent->x_p - extent->x_m),
		fabs(extent->z_p - extent->z_m));
	free(extent);
}
