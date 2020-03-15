/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 01:10:03 by fcals             #+#    #+#             */
/*   Updated: 2020/03/15 11:44:32 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL_image.h>

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width,
	int *height)
{
	SDL_Surface	*tmp;
	SDL_Surface	*image;

	if (!(mlx_ptr) || !(xpm_data) || !(width) || !(height))
		return (NULL);
	if (!(image = IMG_ReadXPMFromArray(xpm_data)))
		return (NULL);
	*width = image->w;
	*height = image->h;
	tmp = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(image);
	image = tmp;
	SDL_LockSurface(image);
	return ((void*)image);
}
