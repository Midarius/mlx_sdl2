/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_data_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:14:30 by fcals             #+#    #+#             */
/*   Updated: 2020/03/14 04:32:28 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line,
	int *endian)
{
	if (!(img_ptr) || !(bits_per_pixel) || !(size_line) || !(endian))
		return (NULL);
	*bits_per_pixel = ((SDL_Surface*)img_ptr)->format->BitsPerPixel;
	*size_line = ((SDL_Surface*)img_ptr)->pitch;
	*endian = 0;
	return (((SDL_Surface*)img_ptr)->pixels);
}
