/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:37:54 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 15:24:09 by fcals            ###   ########.fr       */
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

typedef struct		s_mlx_evt {
	int				set;
	int				(*callback)();
	void			*param;
}					t_mlx_evt;

typedef struct		s_mlx_ptr {
	t_mlx_evt		*event;
	t_mlx_evt		loop;
}					t_mlx_ptr;

typedef struct		s_mlx_window {
	t_mlx_ptr		*mlx_ptr;
	SDL_Window*		window;
	SDL_Renderer*	render;
}					t_mlx_window;

#endif
