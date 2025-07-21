/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:50:28 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 19:43:35 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_other(t_window *game)
{
	if (game->img_wall_ext)
		mlx_destroy_image(game->mlx, game->img_wall_ext);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_fence_down)
		mlx_destroy_image(game->mlx, game->img_fence_down);
	if (game->img_fence_left)
		mlx_destroy_image(game->mlx, game->img_fence_left);
	if (game->img_fence_right)
		mlx_destroy_image(game->mlx, game->img_fence_right);
	if (game->img_fence_up)
		mlx_destroy_image(game->mlx, game->img_fence_up);
}

void	free_struct(t_window *game)
{
	free_other(game);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	free_map(game->map);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
}
