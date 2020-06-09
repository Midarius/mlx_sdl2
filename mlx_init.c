/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:23:02 by fcals             #+#    #+#             */
/*   Updated: 2020/06/09 13:39:11 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <SDL.h>
#include <mlx_private.h>

static int			vector_window_init(t_vector_window *vector,
	unsigned int size)
{
	if (!(vector) || size == 0)
		return (-1);
	if (!(vector->data = malloc(sizeof(t_mlx_window*) * size)))
		return (-1);
	memset(vector->data, 0, sizeof(t_mlx_window*));
	vector->capacity = size;
	vector->size = 0;
	return (0);
}

static t_mlx_ptr	*mlx_ptr_init(void)
{
	t_mlx_ptr *mlx_ptr;

	if (!(mlx_ptr = malloc(sizeof(t_mlx_ptr))))
		return (NULL);
	memset(mlx_ptr, 0, sizeof(t_mlx_ptr));
	if (vector_window_init(&(mlx_ptr->windows), MAX_WINDOWS) == -1)
	{
		free(mlx_ptr);
		return (NULL);
	}
	return (mlx_ptr);
}

void				mlx_exit(void)
{
	unsigned int	i;
	t_mlx_ptr		*mlx_ptr;

	if (!(mlx_ptr = mlx_init()))
		return ;
	i = 0;
	while (i < mlx_ptr->windows.size)
	{
		mlx_destroy_window(mlx_ptr, mlx_ptr->windows.data[i]);
		i++;
	}
	free(mlx_ptr->windows.data);
	free(mlx_ptr);
}

void				*mlx_init(void)
{
	static t_mlx_ptr *mlx_ptr = NULL;

	if (mlx_ptr != NULL)
		return ((void*)mlx_ptr);
	if (!(mlx_ptr = mlx_ptr_init()))
		return (NULL);
	if (SDL_Init(SDL_INIT_VIDEO) != 0 || atexit(SDL_Quit) != 0 ||
	atexit(mlx_exit) != 0)
	{
		SDL_Quit();
		mlx_exit();
		return (NULL);
	}
	return ((void*)mlx_ptr);
}
