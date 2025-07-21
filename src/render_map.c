/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:24:37 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 19:59:20 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	elem_others(t_window *game, int i, int j, char elem)
{
	if (elem == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (elem == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (elem == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_collectible,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (elem == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_exit, j
			* TILE_SIZE, i * TILE_SIZE);
}

void	check_elem_one(t_window *game, int i, int j, int lines)
{
	int	len;

	len = ft_strlen(game->map[0]) - 1;
	if (game->map[0][len] == '\n')
		len--;
	if ((i == 0 && (j == 0 || j == len)) || (i == lines && (j == 0
				|| j == len)))
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall_ext, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (i == 0 && j > 0 && j < len)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_down,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (i == lines && j > 0 && j < len)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_up, j
			* TILE_SIZE, i * TILE_SIZE);
	else if (j == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_right,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (j == len)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_left,
			j * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall, j
			* TILE_SIZE, i * TILE_SIZE);
}

void	render_map(t_window *game)
{
	int		i;
	int		j;
	char	elem;
	int		lines;

	i = -1;
	lines = count_true_line(game->map) - 1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] && game->map[i][j] != '\n')
		{
			elem = game->map[i][j];
			if (elem == '1')
				check_elem_one(game, i, j, lines);
			elem_others(game, i, j, elem);
		}
	}
}
