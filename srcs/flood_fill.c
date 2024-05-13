/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:29:03 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/03 11:16:49 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *data, int x, int y)
{
	if (data->map_temp[y][x] == '1')
		return ;
	if (data->map_temp[y][x] == 'E')
	{
		data->find_exit = 1;
		return ;
	}
	if (data->map_temp[y][x] == 'C')
		data->collect++;
	data->map_temp[y][x] = '1';
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
}
