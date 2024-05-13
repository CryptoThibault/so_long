/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:51:07 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 18:48:37 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(char *file, t_data *data)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Le fichier ne s'ouvre pas correctement\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	data->size.y = get_line_count(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->size.y + 1));
	if (!data->map)
		perror_exit("L'allocation n'a pas fonctionner.", data);
	i = -1;
	while (++i < data->size.y)
	{
		data->map[i] = get_next_line(fd);
		data->map[i][ft_strlen(data->map[i]) - 1] = 0;
	}
	data->map[i] = NULL;
	data->size.x = ft_strlen(data->map[0]);
	close(fd);
}
