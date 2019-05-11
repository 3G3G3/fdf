#include "fdf.h"

void			ft_rotate(t_list *points, double theta_x, double theta_z)
{
	t_point		*point;
	double		x;
	double		y;

	while (points)
	{
	point = (t_point *)(points->content);
	x = point->x;
	y = point->y;
//	point->x = cos(theta_x) * cos(theta_z) * point->x - cos(theta_x) * sin(theta_z) * point->y + sin(theta_x) * point->z;
//	point->y = sin(theta_z) * point->x + cos(theta_z) * point->y;
//	point->z = - sin(theta_x) * cos(theta_z) * point->x + sin(theta_x) * sin(theta_z) * point->y + cos(theta_x) * point->z;
	theta_x = 0;
	point->x = cos(theta_z) * x - sin(theta_z) * y;
	point->y = sin(theta_z) * x + cos(theta_z) * y;
	ft_putnbr(point->x);
	ft_putchar(' ');
	points = points->next;
	}
}

void			ft_parallele_rotate(t_list *param, double theta_x, double theta_z)
{
	ft_putchar('i');
	ft_rotate((param->next)->next, theta_x, theta_z);
	mlx_clear_window(param->content, (param->next)->content);
	ft_parallele_draw((param->next)->next, param->content, (param->next)->content);
}
