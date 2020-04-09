/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:37:54 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 22:57:13 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PRIVATE_H
# define MLX_PRIVATE_H

#include <SDL_render.h>
#include <mlx.h>

/*
** Theses are private structs for mlx_sdl2
** to get SDL2 work as the same behavior as minilibx
*/

#define MAX_WINDOWS 10

typedef struct			s_mlx_evt {
	int					set;
	int					(*callback)();
	void				*param;
}						t_mlx_evt;

struct s_mlx_window;

typedef struct			s_vector_window {
	struct s_mlx_window	**data;
	unsigned int		size;
	unsigned int		capacity;
}						t_vector_window;

typedef struct			s_mlx_ptr {
	t_vector_window		windows;
	t_mlx_evt			loop;
}						t_mlx_ptr;

typedef struct			s_mlx_window {
	t_mlx_ptr			*mlx_ptr;
	SDL_Window*			window;
	SDL_Renderer*		render;
	t_mlx_evt			button_press;
	t_mlx_evt			button_release;
	t_mlx_evt			keyboard_press;
	t_mlx_evt			keyboard_release;
	t_mlx_evt			close;
}						t_mlx_window;



#endif
