/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:46:43 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 19:09:05 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	on_destroy(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	destroy_imgs(t_data *data, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		if (data->imgs[i])
			mlx_destroy_image(data->mlx_ptr, data->imgs[i]);
}

void	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	destroy_imgs(data, 5);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_data(data);
}
