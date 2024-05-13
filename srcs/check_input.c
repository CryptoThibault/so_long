/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:46:23 by tchalaou          #+#    #+#             */
/*   Updated: 2024/03/11 11:46:25 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int ac, char **av)
{
	if (ac != 2)
		perror_exit("Le nombre d'argument n'est pas valide.", NULL);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		perror_exit("Le nom du fichier ne termine pas par .ber.", NULL);
}
