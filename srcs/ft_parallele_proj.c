#include "fdf.h"

t_point			*ft_get_center(t_list *points)
{
	t_point		*center;

	center = ft_memalloc(sizeof(t_point));
	if (center == NULL)
		return (NULL);
	center->x = 0;
	center->y = 0;
	center->z = 0;
	while (points)
	{
		center->x = fmax(center->x, ((t_point *)(points->content))->x);
		center->y = fmax(center->y, ((t_point *)(points->content))->y);
		center->z = fmax(center->z, ((t_point *)(points->content))->z);
		points = points->next;
	}
	return (center);
}

void		ft_center(t_list *points)
{
	t_point		*tmp;
	t_point		*center;

	center = ft_get_center(points);
	while (points != NULL)
	{
		tmp = (t_point *)(points->content);
		tmp->x = tmp->x - (center->x / 2);
		tmp->y = tmp->y - (center->y / 2);
		tmp->z = tmp->z - (center->z / 2);
		points = points->next;
	}

}
void		ft_get_scale_init(t_point *point, t_point *center, int *minx, int *minz)
{
	center->X = point->X;
	center->Z = point->Z;
	*minx = center->X;
	*minz = center->Z;
}

void		ft_get_scale(t_point *point, t_point *center, int *minx, int *minz)
{
	center->X = fmax(center->X, point->X);
	center->Z = fmax(center->Z, point->Z);
	*minx = fmin(center->X, *minx);
	*minz = fmin(center->Z, *minz);
}

t_point		*ft_parallele_proj(t_list *points)
{
	t_point		*tmp;
	t_point		*center;
	int			minx;
	int			minz;

	center = ft_get_center(points);
	if (center == NULL)
		return (NULL);
	tmp = (t_point *)(points->content);
	tmp->X = tmp->x - tmp->y;
	tmp->Z = -1 * (tmp->z - tmp->y);
	ft_get_scale_init(tmp, center, &minx, &minz);
	points = points->next;
	while (points != NULL)
	{
		tmp = (t_point *)(points->content);
		tmp->X = tmp->x - tmp->y;
		tmp->Z = -1 * (tmp->z - tmp->y);
//		tmp->X = (tmp->x - (center->x / 2)) - (tmp->y - (center->y / 2));
//		tmp->Z = -1 * ((tmp->z - (center->z / 2)) - (tmp->y - (center->y / 2)));
		ft_get_scale(tmp, center, &minx, &minz);
		points = points->next;
	}
	center->X = ft_max(center->X, - minx);
	center->Z = ft_max(center->Z, - minz);
	return (center);
}

void			ft_parallele_scale(t_list *points)
{
	t_point		*center;

	center = ft_parallele_proj(points);
	if (center == NULL)
		return ;
	while (points)
	{
		((t_point *)(points->content))->X = W_WIN / 2
//		+ W_WIN * 0.4 * ((t_point *)(points->content))->X / center->X;
		+ 10 * ((t_point *)(points->content))->X;
		((t_point *)(points->content))->Z = H_WIN / 2
//		+ H_WIN * 0.4 * ((t_point *)(points->content))->Z / center->Z;
		+ 10 * ((t_point *)(points->content))->Z;
		ft_putnbr(((t_point *)(points->content))->x);
		points = points->next;
		ft_putchar(' ');
	}
}

void			ft_parallele_draw(t_list *points, void *mlx_ptr, void *win_ptr)
{
//	ft_parallele_proj(points);
	ft_parallele_scale(points);
	ft_draw(points, mlx_ptr, win_ptr);
}
