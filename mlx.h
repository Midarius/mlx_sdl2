/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:37:54 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 21:54:39 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

#include <SDL_render.h>

/*
** Theses are private structs for mlx_sdl2
** to get SDL2 work as the same behavior as minilibx
*/

typedef struct		s_mlx_evt {
	int				(*callback)();
	void			*param;
}					t_mlx_evt;

typedef struct		s_mlx_ptr {
	t_mlx_evt		*event;
	int				windows;
	SDL_Renderer*	render;
}					t_mlx_ptr;

typedef struct		s_mlx_window {
	t_mlx_ptr		*mlx_ptr;
	SDL_Window*		window;
	SDL_Renderer*	render;
}					t_mlx_window;

/*
** minilibx prototypes
** Use SDL2 lib
*/

void				*mlx_init(void);
void				*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
	char *title);
int					mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int					mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
	void *img_ptr, int x, int y);
void				*mlx_new_image(void *mlx_ptr, int width, int height);
int					mlx_destroy_image(void *mlx_ptr, void *img_ptr);
char				*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
	int *size_line, int *endian);
int					mlx_get_screen_size(void *mlx_ptr, int *sizex,
	int *sizey);
int					mlx_loop(void *mlx_ptr);
int					mlx_hook(void *win_ptr, int x_event, int x_mask,
	int (*funct)(), void *param);
int					mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
int					mlx_key_hook (void *win_ptr, int (*f)(), void *param);

/*
** Use SDL_Image extension
*/

void				*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
	int *width, int *height);

#endif
