/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:44 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/13 14:42:48 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map(t_data *data)
{
	if (data->map[data->player.y][data->player.x] == 'C')
	{
		data->collect++;
		data->map[data->player.y][data->player.x] = '0';
	}
	if (data->player.x == data->exit.x && data->player.y == data->exit.y
		&& data->collect == data->target)
	{
		on_destroy(data);
		exit(EXIT_SUCCESS);
	}
}
