/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:52:24 by fcals             #+#    #+#             */
/*   Updated: 2020/06/09 13:25:51 by fcals            ###   ########.fr       */
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
	return ((void*)image);
}
