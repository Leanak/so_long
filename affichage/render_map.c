/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:24:37 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/20 21:44:40 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_images(t_window *game)
{
	game->img_wall_ext = mlx_xpm_file_to_image(game->mlx, "imgs/wall_ext.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &game->img_width, &game->img_height);	
	game->img_fence_down = mlx_xpm_file_to_image(game->mlx, "imgs/fence_down.xpm", &game->img_width, &game->img_height);
	game->img_fence_up = mlx_xpm_file_to_image(game->mlx, "imgs/fence_up.xpm", &game->img_width, &game->img_height);
	game->img_fence_left = mlx_xpm_file_to_image(game->mlx, "imgs/fence_left.xpm", &game->img_width, &game->img_height);
	game->img_fence_right = mlx_xpm_file_to_image(game->mlx, "imgs/fence_right.xpm", &game->img_width, &game->img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "imgs/collectible.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &game->img_width, &game->img_height);
}

void	render_map(t_window *game)
{
	int		i;
	int		j;
	char	elem;
	int		lines;
	int		len;

	i = 0;
	lines = count_true_line(game->map) - 1;
	len = ft_strlen(game->map[0]) - 1;
	if (game->map[0][len] == '\n')
		len--;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			elem = game->map[i][j];
			if (elem == '1')
			{
				if ((i == 0 && (j == 0 || j == len)) || (i == lines && (j == 0 || j == len)))
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall_ext, j * TILE_SIZE, i * TILE_SIZE);				
				else if (i == 0 && j > 0 && j < len)
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_down, j * TILE_SIZE, i * TILE_SIZE);
				else if (i == lines && j > 0 && j < len)
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_up, j * TILE_SIZE, i * TILE_SIZE);
				else if (j == 0)
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_right, j * TILE_SIZE, i * TILE_SIZE);
				else if (j == len)
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_fence_left, j * TILE_SIZE, i * TILE_SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_wall, j * TILE_SIZE, i * TILE_SIZE);				
			}
			else if (elem == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_player, j * TILE_SIZE, i * TILE_SIZE);
			else if (elem == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_floor, j * TILE_SIZE, i * TILE_SIZE);
			else if (elem == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_collectible, j * TILE_SIZE, i * TILE_SIZE);
			else if (elem == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_exit, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

