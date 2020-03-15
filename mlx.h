/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:37:54 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 18:35:42 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

/*
** minilibx prototypes
** Use SDL2 lib
*/

void			*mlx_init(void);
void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
	char *title);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
	void *img_ptr, int x, int y);
void			*mlx_new_image(void *mlx_ptr, int width, int height);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
	int *size_line, int *endian);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				mlx_loop(void *mlx_ptr);
int				mlx_hook(void *win_ptr, int x_event, int x_mask,
	int (*funct)(), void *param);
int				mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
int				mlx_key_hook(void *win_ptr, int (*f)(), void *param);
int				mlx_mouse_hook(void *win_ptr, int (*f)(), void *param);
int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_mouse_show(void);
int				mlx_mouse_hide(void);

/*
** Use SDL_Image extension
*/

void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
	int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
	int *width, int *height);

/*
** Todo: SDL_ttf
**
** int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
** char *string);
*/

/*
** NYI
*/

unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
	int color, char *string);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
	int color);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_mouse_move(void *win_ptr, int x, int y);
int				mlx_do_sync(void *mlx_ptr);

#endif
