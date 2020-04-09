/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:44:48 by fcals             #+#    #+#             */
/*   Updated: 2020/04/09 22:43:40 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <mlx_private.h>

static int	mlx_add_window(t_mlx_ptr *ptr, t_mlx_window *win)
{
	if (ptr->windows.size == ptr->windows.capacity)
		return (-1);
	ptr->windows.data[ptr->windows.size] = win;
	ptr->windows.size++;
	return (0);
}

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_mlx_window *win_ptr;

	if (!(mlx_ptr) || !(title))
		return (NULL);
	if (!(win_ptr = malloc(sizeof(t_mlx_window))))
		return (NULL);
	if (mlx_add_window(mlx_ptr, win_ptr) == -1)
	{
		free(win_ptr);
		return (NULL);
	}
	if (!(win_ptr->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, size_x, size_y, SDL_WINDOW_OPENGL)))
	{
		free(win_ptr);
		return (NULL);
	}
	if (!(win_ptr->render = SDL_CreateRenderer(win_ptr->window, -1,
		SDL_RENDERER_ACCELERATED)))
	{
		SDL_DestroyWindow(win_ptr->window);
		free(win_ptr);
		return (NULL);
	}
	win_ptr->mlx_ptr = (t_mlx_ptr*)mlx_ptr;
	return ((void*)win_ptr);
}
