/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:59:42 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 16:32:28 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	write_position(t_pos *position, t_pos pos, int *find)
{
	*position = pos;
	*find = 1;
}

t_pos	get_position(t_data *data, char c)
{
	int		find;
	t_pos	position;
	t_pos	pos;

	find = 0;
	pos.y = 0;
	while (++pos.y < data->size.y)
	{
		pos.x = 0;
		while (++pos.x < data->size.x)
		{
			if (data->map[pos.y][pos.x] == c)
			{
				if (!find)
					write_position(&position, pos, &find);
				else
					perror_exit("Un element est en trop.", data);
			}
		}
	}
	if (!find)
		perror_exit("Un element est introuvable.", data);
	return (position);
}
