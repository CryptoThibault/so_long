/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collect_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:46:54 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 16:14:31 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_collect_count(t_data *data)
{
	int		count;
	t_pos	pos;

	count = 0;
	pos.y = 0;
	while (++pos.y < data->size.y)
	{
		pos.x = 0;
		while (++pos.x < data->size.x)
			if (data->map[pos.y][pos.x] == 'C')
				count++;
	}
	if (count < 1)
		perror_exit("La carte doit contenir un collectible minimum", data);
	return (count);
}
