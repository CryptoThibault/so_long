/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:34:54 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/03 14:52:45 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	check_input(ac, av);
	data = malloc(sizeof(t_data));
	if (!data)
		perror_exit("L'allocation n'a pas fonctionner.", NULL);
	create_map(av[1], data);
	check_map(data);
	data->player = get_position(data, 'P');
	data->exit = get_position(data, 'E');
	data->target = get_collect_count(data);
	data->find_exit = 0;
	data->collect = 0;
	data->map_temp = dup_array(data->map, data->size.y);
	flood_fill(data, data->player.x, data->player.y);
	free_array(data->map_temp);
	if (!data->find_exit)
		perror_exit("La sortie n'est pas accessible", data);
	if (data->collect != data->target)
		perror_exit("Les collectibles ne sont pas tous accessible", data);
	data->collect = 0;
	so_long(data);
	return (EXIT_SUCCESS);
}
