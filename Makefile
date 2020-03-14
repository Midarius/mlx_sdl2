CC = gcc

CFLAGS = -Wall -Wextra -Werror
INC = -I.

NAME = libmlx.a

SRC =	mlx_destroy_image.c\
		mlx_destroy_window.c\
		mlx_get_data_addr.c\
		mlx_get_screen_size.c\
		mlx_hook.c\
		mlx_init.c\
		mlx_loop.c\
		mlx_new_image.c\
		mlx_new_window.c\
		mlx_put_image_to_window.c\
		mlx_xpm_file_to_image.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
