NAME = fdf

SRC_PATH = ./srcs/
LIBFT_PATH = ./libft/
MINILIBX_PATH = ./minilibx_macos/
INC_PATH = ./includes/

CC = gcc
#DEBUG_FLAGS = -fsanitize=address
DEBUG_FLAGS =  
CFLAGS = -Wall -Werror -Wextra -I $(INC_PATH) -I $(LIBFT_PATH) -g3
MINILIBX_FLAGS = -I $(MINILIBX_PATH) -L $(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

LIBFT = $(LIBFT_PATH)libft.a

SRCS = main.c					\
		ft_parsefile_tools.c	\
		ft_parsefile.c			\
		ft_init_lst.c			\
		ft_adjust_position.c	\
		ft_extent.c				\
		ft_move.c				\
		ft_keys_tools.c			\
		ft_keys2.c				\
		ft_keys.c				\
		ft_window_position.c	\
		ft_projection.c			\
		ft_draw.c				\
		ft_draw_line_octantr.c	\
		ft_draw_line_octantl.c	\
		ft_draw_line.c			\
		ft_free.c				\
		ft_exit.c				\
		ft_tools.c

SRC = $(addprefix $(SRC_PATH), $(SRCS))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C $(MINILIBX_PATH)
	$(CC) $(DEBUG_FLAGS) $(MINILIBX_FLAGS) -o $(NAME)  $(LIBFT) $(OBJ)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
