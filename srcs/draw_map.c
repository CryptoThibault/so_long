/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:04 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/13 15:02:34 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	draw_player(t_data *data)
{
	static int	count;
	char		*count_str;

	if (!count)
		count = 0;
	count++;
	mlx_string_put(data->mlx_ptr, data->win_ptr, TILE_SIZE, TILE_SIZE / 2,
		0xFF0000, "Current moves :");
	count_str = ft_itoa(count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, TILE_SIZE * 4, TILE_SIZE / 2,
		0xFF0000, count_str);
	free(count_str);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgs[2],
		data->player.x * TILE_SIZE, data->player.y * TILE_SIZE);
}

void	draw_map(t_data *data)
{
	t_pos	pos;
	int		i;

	pos.y = -1;
	while (++pos.y < data->size.y)
	{
		pos.x = -1;
		while (++pos.x < data->size.x)
		{
			if (data->map[pos.y][pos.x] == '0')
				i = 0;
			if (data->map[pos.y][pos.x] == '1')
				i = 1;
			if (data->map[pos.y][pos.x] == 'P')
				i = 0;
			if (data->map[pos.y][pos.x] == 'C')
				i = 3;
			if (data->map[pos.y][pos.x] == 'E')
				i = 4;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->imgs[i], pos.x * TILE_SIZE, pos.y * TILE_SIZE);
		}
	}
	draw_player(data);
}
