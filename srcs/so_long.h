/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:37:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/05/07 19:08:50 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define TILE_SIZE 32

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*imgs[5];
	char	**map;
	char	**map_temp;
	t_pos	dims;
	t_pos	size;
	t_pos	player;
	t_pos	exit;
	int		find_exit;
	int		collect;
	int		target;
}		t_data;

void	check_input(int ac, char **av);
void	perror_exit(char *msg, t_data *data);
void	free_data(t_data *data);
void	free_array(char **array);
void	create_map(char *file, t_data *data);
int		get_line_count(int fd);
void	check_map(t_data *data);
t_pos	get_position(t_data *data, char c);
int		get_collect_count(t_data *data);
char	**dup_array(char **array, int size);
void	flood_fill(t_data *data, int x, int y);
void	so_long(t_data *data);
void	load_images(t_data *data);
void	draw_map(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	update_map(t_data *data);
void	on_destroy(t_data *data);
void	destroy_imgs(t_data *data, int nb);
int		close_window(t_data *data);

#endif
