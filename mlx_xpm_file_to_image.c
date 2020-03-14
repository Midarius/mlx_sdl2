/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_file_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:33:34 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 04:27:59 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL_image.h>

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width,
	int *height)
{
	SDL_Surface	*tmp;
	SDL_Surface	*image;
	SDL_RWops	*rwop;

	if (!(mlx_ptr) || !(filename) || !(width) || !(height))
		return (NULL);
	rwop = SDL_RWFromFile(filename, "rb");
	if (!(image = IMG_LoadXPM_RW(rwop)))
		return (NULL);
	SDL_RWclose(rwop);
	*width = image->w;
	*height = image->h;
	tmp = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(image);
	image = tmp;
	SDL_LockSurface(image);
	return ((void*)image);
}
