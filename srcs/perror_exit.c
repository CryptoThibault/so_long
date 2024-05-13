/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:47:52 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 18:49:08 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_exit(char *msg, t_data *data)
{
	ft_printf("Error: %s\n", msg);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}
