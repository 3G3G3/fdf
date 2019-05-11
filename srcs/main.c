#include "fdf.h"

int			main(int argc, char **argv)
{
	t_list		*points;
//	void		*mlx_ptr;
//	void		*win_ptr;
	t_list		*ptrs;

	if (argc != 2)
		return (-1);
	points = ft_readfile(argv[1]);
//	ft_center(points);
	if (points == NULL)
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
	ptrs = ft_init_lst(argv[1]);
	if (ptrs == NULL)
		return (1);
	((ptrs->next)->next)->next = points;
	ft_draw(ptrs);
	mlx_key_hook((ptrs->next)->content, &ft_keys, ptrs);
	mlx_loop(ptrs->content);
//	+ clear list + perror
	return (0);
}

/*
** fuite mémoire quand carte bonne mais espace suplémentaire ('1 1 0  1  0)
** test sur des cartes à une seule ligne / colonne, un point unique
*/
