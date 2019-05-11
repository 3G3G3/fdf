#include "fdf.h"

int			ft_keys(int keycode, void *param)
{
	ft_putnbrendl(keycode);
	if (keycode == 123)
		ft_parallele_rotate(param, 0, M_PI / 32);
	else if (keycode == 124)
		ft_parallele_rotate(param, 0, - M_PI / 32);
	else if (keycode == 37)
		ft_translate(-1, param);
	else if (keycode == 15)
		ft_translate(1, param);
	else if (keycode == 53)
		ft_exit(param);
	return (0);
}
