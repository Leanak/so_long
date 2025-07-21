/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:33:18 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 21:32:24 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

static void	flood_fill(char **dup, int x, int y)
{
	int	len;
	int	lines;

	len = ft_strlen(dup[0]);
	if (dup[0][len - 1] == '\n')
		len--;
	lines = count_true_line(dup);
	if (x < 0 || y < 0 || x >= len || y >= lines)
		return ;
	if (dup[y][x] == '1' || dup[y][x] == 'V' || dup[y][x] == 'E')
		return ;
	dup[y][x] = 'V';
	flood_fill(dup, x - 1, y);
	flood_fill(dup, x, y - 1);
	flood_fill(dup, x + 1, y);
	flood_fill(dup, x, y + 1);
}

static int	check_dup(char **dup)
{
	int	i;
	int	j;
	int	len;
	int	lines;

	len = ft_strlen(dup[0]);
	if (dup[0][len - 1] == '\n')
		len--;
	lines = count_true_line(dup);
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < len)
		{
			if (dup[i][j] != 'V' && dup[i][j] != '1' && dup[i][j] != '0'
				&& dup[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	find_player(char **dup, t_window *game)
{
	int	i;
	int	j;
	int	len;
	int	lines;

	len = ft_strlen(dup[0]);
	if (dup[0][len - 1] == '\n')
		len--;
	lines = count_true_line(dup);
	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < len)
		{
			if (dup[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
		}
	}
}

int	check_playability(char **map, t_window *game)
{
	char	**dup;
	int		result;

	dup = dup_map(map);
	if (!dup)
		return (0);
	find_player(dup, game);
	flood_fill(dup, game->x, game->y);
	result = check_dup(dup);
	if (result == 0)
		return (free_map(dup), 0);
	free_map(dup);
	return (1);
}
