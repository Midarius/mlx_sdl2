CC = gcc

CFLAGS = -Wall -Wextra -Werror -O2 -D USE_SDL_IMAGE
INC = -I.

NAME = libmlx.a

SRC =	mlx_clear_window.c\
		mlx_destroy_image.c\
		mlx_destroy_window.c\
		mlx_do_key_autorepeat.c\
		mlx_do_sync.c\
		mlx_get_color_value.c\
		mlx_get_data_addr.c\
		mlx_get_screen_size.c\
		mlx_hook.c\
		mlx_init.c\
		mlx_loop.c\
		mlx_mouse_get_pos.c\
		mlx_mouse_hide.c\
		mlx_mouse_move.c\
		mlx_mouse_show.c\
		mlx_new_image.c\
		mlx_new_window.c\
		mlx_pixel_put.c\
		mlx_put_image_to_window.c\
		mlx_string_put.c\
		mlx_xpm_file_to_image.c\
		mlx_xpm_to_image.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I.

.PHONY: clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
