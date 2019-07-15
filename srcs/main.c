#include "fdf.h"

t_list			*ft_init(char *argv)
{
	t_list		*points;
	t_list		*res;

	points = ft_readfile(argv);
	if (points == NULL)
		exit (-1);
	res = ft_init_lst(argv);
	if (res == NULL)
		exit (-1);
//	free points
	((res->next)->next)->next = points;
	ft_center(points);
	ft_move(res);
	ft_projection(res);
	ft_get_extent(res);
	return (res);
}

int				main(int argc, char **argv)
{
//	void		*mlx_ptr;
//	void		*win_ptr;
	t_list		*ptrs;

	if (argc != 2)
		return (-1);
//	+ perror
/*	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);
// + clear list + perror
	win_ptr = mlx_new_window(mlx_ptr, W_WIN, H_WIN, argv[1]);
	if (win_ptr == NULL)
		return (-1);

	ptrs = ft_lstnew(NULL, 0);
	ft_lstadd(&ptrs, ft_lstnew(NULL, 0));
	(ptrs->content) = mlx_ptr;
	((ptrs->next)->content) = win_ptr;
	(ptrs->next)->next = points;
	*/
// protection
	ptrs = ft_init(argv[1]);
	ft_draw(ptrs);
	mlx_key_hook((ptrs->next)->content, &ft_keys, ptrs);
	mlx_loop(ptrs->content);
//	+ clear list + perror
	return (0);
}

/*
** projection en perspective

** fuite mémoire quand carte bonne mais espace suplémentaire ('1 1 0  1  0)
** test sur des cartes à une seule ligne / colonne, un point unique
** fuite mémoire sur carte invalide
** fuite mémoire sur malloc erreur
*/
