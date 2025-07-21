/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:50:28 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 20:15:20 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	destroy_other(t_window *game)
{
	if (game->collect_anim)
		free(game->collect_anim);
	if (game->img_ennemy)
		mlx_destroy_image(game->mlx, game->img_ennemy);
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
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
}

void	free_struct(t_window *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->collect_anim && game->collect_anim->frames[i])
		{
			mlx_destroy_image(game->mlx, game->collect_anim->frames[i]);
		}
		i++;
	}
	destroy_other(game);
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
