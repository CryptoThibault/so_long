/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:46:01 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/13 14:36:05 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	t_pos	last;

	last = data->player;
	if (keysym == XK_w && data->map[data->player.y - 1][data->player.x] != '1')
		data->player.y--;
	if (keysym == XK_s && data->map[data->player.y + 1][data->player.x] != '1')
		data->player.y++;
	if (keysym == XK_a && data->map[data->player.y][data->player.x - 1] != '1')
		data->player.x--;
	if (keysym == XK_d && data->map[data->player.y][data->player.x + 1] != '1')
		data->player.x++;
	if (data->player.y != last.y || data->player.x != last.x)
	{
		update_map(data);
		draw_map(data);
	}
	if (keysym == XK_Escape)
	{
		on_destroy(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
