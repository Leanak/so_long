/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:45:13 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/20 23:28:45 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
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
	game->mlx_win = mlx_new_window(game->mlx, game->img_width, game->img_height, "So_long game");
	if (!game->mlx_win)
		return (0);
	return (1);
}

t_window *init_game(t_window *game)
{
	game = malloc(sizeof(t_window));
	if (!game)
		exit (1);
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
	t_window	*game = NULL;

	if (ac != 2)
		return (1);
	game = init_game(game);
	game->map = read_map(av[1], game);
	if (!game->map || !game)
	{
		if (game)
			free_struct(game);
		return (1);
	}
	if (!init_window(game))
	{
		free_struct(game);
		return (1);
	}
	init_images(game);
	render_map(game);
	mlx_key_hook(game->mlx_win, handle_key, game);
	mlx_loop(game->mlx);
	free_struct(game);
	return (0);
}
