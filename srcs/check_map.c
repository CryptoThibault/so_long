/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:03:38 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/06 15:41:23 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data)
{
	t_pos	pos;

	pos.y = -1;
	while (++pos.y < data->size.y)
	{
		if ((int)ft_strlen(data->map[pos.y]) != data->size.x)
			perror_exit("La carte doit etre de forme rectangulaire.",
				data);
		pos.x = -1;
		while (++pos.x < data->size.x)
		{
			if (!ft_strchr("01PCE", data->map[pos.y][pos.x]))
				perror_exit("La carte contient un element inconnu", data);
			if (pos.y == 0 || pos.y == data->size.y - 1 || pos.x == 0
				|| pos.x == data->size.x - 1)
			{
				if (data->map[pos.y][pos.x] != '1')
					perror_exit("La carte doit etre encadree par des murs.",
						data);
			}
		}
	}
}
