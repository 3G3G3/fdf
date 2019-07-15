#include "fdf.h"

void		ft_set_point(t_line *line, int x1, int y1, int x2, int y2)
{
	line->x1 = x1;
	line->y1 = y1;
	line->x2 = x2;
	line->y2 = y2;
}

int			ft_test_quadran(int i, int j, int m, int n)
{
	if (j >= i && n >= m)
		return (1);
	return (0);
}

int			ft_test_growth(int i, int j)
{
	if (j >= i)
		return (1);
	return (0);
}

t_line		*ft_define_line(t_point *point1, t_point *point2)
{
	t_line	*line;

	line = ft_memalloc(sizeof(t_line));
	if (line == NULL)
		return (NULL);
	ft_set_point(line, point1->x_w, point1->z_w, point2->x_w, point2->z_w);
	line->dy = 2 * (line->y2 - line->y1);
	line->dx = 2 * (line->x2 - line->x1);
	line->e = line->x2 - line->x1;
	return (line);
}

void		ft_put_octant1(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (x < line->x2)
	{
		ft_draw_point(x, y, param);
		x = x + 1;
		line->e = line->e - line->dy;
		if (line->e < 0)
		{
			y = y + 1;
			line->e = line->e + line->dx;
		}
	}
}

void		ft_put_octant8(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (x < line->x2)
	{
		ft_draw_point(x, y, param);
		x = x + 1;
		line->e = line->e + line->dy;
		if (line->e < 0)
		{
			y = y - 1;
			line->e = line->e + line->dx;
		}
	}
}

void		ft_put_octant2(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (y < line->y2)
	{
		ft_draw_point(x, y, param);
		y = y + 1;
		line->e = line->e - line->dx;
		if (line->e < 0)
		{
			x = x + 1;
			line->e = line->e + line->dy;
		}
	}
}

void		ft_put_octant7(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (y > line->y2)
	{
		ft_draw_point(x, y, param);
		y = y - 1;
		line->e = line->e + line->dx;
		if (line->e > 0)
		{
			x = x + 1;
			line->e = line->e + line->dy;
		}
	}
}

void		ft_put_octant5(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (x > line->x2)
	{
		ft_draw_point(x, y, param);
		x = x - 1;
		line->e = line->e - line->dy;
		if (line->e >= 0)
		{
			y = y - 1;
			line->e = line->e + line->dx;
		}
	}
}

void		ft_put_octant4(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (x > line->x2)
	{
		ft_draw_point(x, y, param);
		x = x - 1;
		line->e = line->e + line->dy;
		if (line->e >= 0)
		{
			y = y + 1;
			line->e = line->e + line->dx;
		}
	}
}

void		ft_put_octant6(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (y > line->y2)
	{
		ft_draw_point(x, y, param);
		y = y - 1;
		line->e = line->e - line->dx;
		if (line->e >= 0)
		{
			x = x - 1;
			line->e = line->e + line->dy;
		}
	}
}

void		ft_put_octant3(t_line *line, t_list *param)
{
	int		x;
	int		y;

	x = line->x1;
	y = line->y1;
	while (y < line->y2)
	{
		ft_draw_point(x, y, param);
		y = y + 1;
		line->e = line->e + line->dx;
		if (line->e <= 0)
		{
			x = x - 1;
			line->e = line->e + line->dy;
		}
	}
}

void		ft_draw_line(t_point *point1, t_point *point2, t_list *param)
{
	t_line	*line;

	line = ft_define_line(point1, point2);
	if (line == NULL)
		return ;
	if (ft_test_quadran(point1->z_w, point2->z_w, point1->x_w, point2->x_w)
			&& ft_test_growth(point2->z_w - point1->z_w, point2->x_w - point1->x_w))
		ft_put_octant1(line, param);

	else if (ft_test_quadran(point1->z_w, point2->z_w, point1->x_w, point2->x_w)
			&& ft_test_growth(point2->x_w - point1->x_w, point2->z_w - point1->z_w))
		ft_put_octant2(line, param);

	else if (ft_test_quadran(point1->z_w, point2->z_w, point2->x_w, point1->x_w)
			&& ft_test_growth(point1->x_w - point2->x_w, point2->z_w - point1->z_w))
		ft_put_octant3(line, param);

	else if (ft_test_quadran(point1->z_w, point2->z_w, point2->x_w, point1->x_w)
			&& ft_test_growth(point2->z_w - point1->z_w, point1->x_w - point2->x_w))
		ft_put_octant4(line, param);

	else if (ft_test_quadran(point2->z_w, point1->z_w, point2->x_w, point1->x_w)
			&& ft_test_growth(point1->z_w - point2->z_w, point1->x_w - point2->x_w))
		ft_put_octant5(line, param);

	else if (ft_test_quadran(point2->z_w, point1->z_w, point2->x_w, point1->x_w)
			&& ft_test_growth(point1->x_w - point2->x_w, point1->z_w - point2->z_w))
		ft_put_octant6(line, param);

	else if (ft_test_quadran(point2->z_w, point1->z_w, point1->x_w, point2->x_w)
			&& ft_test_growth(point2->x_w - point1->x_w, point1->z_w - point2->z_w))
		ft_put_octant7(line, param);

	else if (ft_test_quadran(point2->z_w, point1->z_w, point1->x_w, point2->x_w)
			&& ft_test_growth(point1->z_w - point2->z_w, point2->x_w - point1->x_w))
		ft_put_octant8(line, param);
	free(line);
}
