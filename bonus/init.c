/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:42:14 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 20:28:16 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_collect(t_window *game)
{
	game->collect_anim->frames[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/collectible.xpm", &game->img_width, &game->img_height);
	if (!game->collect_anim->frames[0])
		exit_game(game);
	game->collect_anim->frames[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/pink.xpm", &game->img_width, &game->img_height);
	if (!game->collect_anim->frames[1])
		exit_game(game);
	game->collect_anim->frames[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/blue.xpm", &game->img_width, &game->img_height);
	if (!game->collect_anim->frames[2])
		exit_game(game);
	game->collect_anim->current = 0;
	game->collect_anim->frame_count = 3;
	game->collect_anim->timer = 0;
}

void	init_other(t_window *game)
{
	game->img_ennemy = mlx_xpm_file_to_image(game->mlx, "imgs/ennemy.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_ennemy)
		exit_game(game);
	game->img_wall_ext = mlx_xpm_file_to_image(game->mlx, "imgs/wall_ext.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall_ext)
		exit_game(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall)
		exit_game(game);
	game->img_fence_down = mlx_xpm_file_to_image(game->mlx,
			"imgs/fence_down.xpm", &game->img_width, &game->img_height);
	if (!game->img_fence_down)
		exit_game(game);
	game->img_fence_up = mlx_xpm_file_to_image(game->mlx, "imgs/fence_up.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_fence_up)
		exit_game(game);
}

void	init_images(t_window *game)
{
	init_collect(game);
	init_other(game);
	game->img_fence_left = mlx_xpm_file_to_image(game->mlx,
			"imgs/fence_left.xpm", &game->img_width, &game->img_height);
	if (!game->img_fence_left)
		exit_game(game);
	game->img_fence_right = mlx_xpm_file_to_image(game->mlx,
			"imgs/fence_right.xpm", &game->img_width, &game->img_height);
	if (!game->img_fence_right)
		exit_game(game);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_floor)
		exit_game(game);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_player)
		exit_game(game);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_exit)
		exit_game(game);
}
