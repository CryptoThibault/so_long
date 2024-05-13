/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:03:18 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/03 12:45:40 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_array(char **array, int size)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size)
		copy[i] = ft_strdup(array[i]);
	copy[i] = NULL;
	return (copy);
}
