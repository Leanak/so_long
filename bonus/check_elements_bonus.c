/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:48:29 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 16:39:27 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_p(char **map)
{
	int	i;
	int	j;
	int	len;
	int	lines;
	int	count;

	count = 0;
	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	lines = count_true_line(map);
	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < len)
		{
			if (map[i][j] == 'P')
				count++;
		}
	}
	return (count);
}

static int	bubble_check(char **map, int len, int lines, t_window *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < len)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'X')
				return (0);
			if (map[i][j] == 'C')
				game->collect_max++;
			if (map[i][j] == 'E')
				game->exit_max++;
		}
	}
	if (game->collect_max < 1 || game->exit_max != 1)
		return (0);
	return (1);
}

static int	check_ec(char **map, t_window *game)
{
	int	len;
	int	lines;

	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	lines = count_true_line(map);
	if (!bubble_check(map, len, lines, game))
		return (0);
	return (1);
}

int	check_elements(char **map, t_window *game)
{
	if (check_p(map) != 1)
		return (0);
	if (check_ec(map, game) == 0)
		return (0);
	return (1);
}
