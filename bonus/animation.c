/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:53:19 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 20:16:00 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	update_animation(t_window *game)
{
	game->collect_anim->timer++;
	if (game->collect_anim->timer >= 200)
	{
		game->collect_anim->timer = 0;
		game->collect_anim->current++;
		if (game->collect_anim->current >= game->collect_anim->frame_count)
			game->collect_anim->current = 0;
	}
}

void	write_moves(t_window *game)
{
	char	*str_step;

	str_step = ft_itoa(game->step);
	if (!str_step)
		exit_game(game);
	mlx_string_put(game->mlx, game->mlx_win, 10, 20, 0x00000, "Steps :");
	mlx_string_put(game->mlx, game->mlx_win, 70, 20, 0x00000, str_step);
	free(str_step);
}

int	update_and_render(t_window *game)
{
	update_animation(game);
	render_map(game);
	return (0);
}
