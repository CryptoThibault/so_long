/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:45:18 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 19:10:11 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_image(t_data *data, int nb)
{
	destroy_imgs(data, nb);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	perror_exit("Une des image n'a pas charger correctement", data);
}

void	load_images(t_data *data)
{
	data->imgs[0] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/img0.xpm",
			&data->dims.x, &data->dims.y);
	if (!data->imgs[0])
		error_image(data, 1);
	data->imgs[1] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/img1.xpm",
			&data->dims.x, &data->dims.y);
	if (!data->imgs[1])
		error_image(data, 2);
	data->imgs[2] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/imgP.xpm",
			&data->dims.x, &data->dims.y);
	if (!data->imgs[2])
		error_image(data, 3);
	data->imgs[3] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/imgC.xpm",
			&data->dims.x, &data->dims.y);
	if (!data->imgs[3])
		error_image(data, 4);
	data->imgs[4] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/imgE.xpm",
			&data->dims.x, &data->dims.y);
	if (!data->imgs[4])
		error_image(data, 5);
}
