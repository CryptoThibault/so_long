/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:40:17 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 19:09:33 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		perror_exit("mlx_ptr ne charge pas", data);
	load_images(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size.x * TILE_SIZE,
			data->size.y * TILE_SIZE, "so long");
	if (!data->win_ptr)
	{
		destroy_imgs(data, 5);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		perror_exit("win_ptr ne charge pas", data);
	}
	draw_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, &close_window, data);
	mlx_loop(data->mlx_ptr);
	on_destroy(data);
}
