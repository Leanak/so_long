/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:00:00 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 20:12:09 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	exit_game(t_window *game)
{
	free_struct(game);
	exit(1);
}

void	game_change(t_window *game, int new_x, int new_y)
{
	game->map[game->y][game->x] = '0';
	game->map[new_y][new_x] = 'P';
	game->x = new_x;
	game->y = new_y;
	game->step++;
	ft_printf("Moves : %d\n", game->step);
	render_map(game);
}

void	print_exit_game(t_window *game)
{
	ft_printf("NULLLLLL TU ES NULL\n");
	exit_game(game);
}

void	try_move(t_window *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = game->x + x;
	new_y = game->y + y;
	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'C')
		game->collect++;
	if (target == 'E' || target == 'X')
	{
		if (game->collect == game->collect_max)
		{
			ft_printf("OK BRAVO\n");
			exit_game(game);
		}
		else if (target == 'X')
			print_exit_game(game);
		return ;
	}
	game_change(game, new_x, new_y);
}

int	handle_key(int keycode, t_window *game)
{
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == UP || keycode == W)
		try_move(game, 0, -1);
	else if (keycode == DOWN || keycode == S)
		try_move(game, 0, 1);
	else if (keycode == LEFT || keycode == A)
		try_move(game, -1, 0);
	else if (keycode == RIGHT || keycode == D)
		try_move(game, 1, 0);
	return (0);
}
