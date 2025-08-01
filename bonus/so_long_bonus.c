/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:50:00 by lenakach          #+#    #+#             */
/*   Updated: 2025/08/01 13:54:45 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	close_window(t_window *game)
{
	free_struct(game);
	exit(1);
	return (0);
}

int	check_ber(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.')
		return (0);
	return (1);
}

int	init_window(t_window *game)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	map_width = ft_strlen(game->map[0]) - 1;
	while (game->map[map_height])
		map_height++;
	game->img_width = map_width * TILE_SIZE;
	game->img_height = map_height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, game->img_width, game->img_height,
			"So_long game");
	if (!game->mlx_win)
		return (0);
	return (1);
}

t_window	*init_game(t_window *game)
{
	game = malloc(sizeof(t_window));
	if (!game)
		exit(1);
	ft_bzero(game, sizeof(t_window));
	game->collect_anim = malloc(sizeof(t_anim));
	if (!game->collect_anim)
		free_struct(game);
	ft_bzero(game->collect_anim, sizeof(t_anim));
	game->map = NULL;
	game->x = 0;
	game->y = 0;
	game->collect_max = 0;
	game->collect = 0;
	game->exit_max = 0;
	game->step = 0;
	return (game);
}

int	main(int ac, char **av)
{
	t_window	*game;

	game = NULL;
	if (ac != 2 || check_ber(av[1]) == 1)
	{
		if (check_ber(av[1]) == 1)
			ft_putstr_fd("Map .ber error\n", 2);
		return (1);
	}
	game = init_game(game);
	game->map = read_map(av[1], game);
	if (!game->map || !game || !init_window(game))
	{
		if (game)
			free_struct(game);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	init_images(game);
	render_map(game);
	mlx_loop_hook(game->mlx, update_and_render, game);
	mlx_key_hook(game->mlx_win, handle_key, game);
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free_struct(game);
	return (0);
}
