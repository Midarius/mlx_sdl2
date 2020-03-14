/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:52:24 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 21:47:52 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

void	*mlx_new_image(void *mlx_ptr, int width, int height)
{
	SDL_Surface *image;

	if (!(mlx_ptr))
		return (NULL);
	if (!(image = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32,
		SDL_PIXELFORMAT_ARGB8888)))
		return (NULL);
	// SDL_LockSurface(image);
	return ((void*)image);
}
