/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:56:09 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 16:31:01 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_parsing(char **map, t_window *game)
{
	int	len;

	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	if (!is_rectangle(map) || !is_mur(map) || !check_elements(map, game)
		|| !check_playability(map, game) || len < 3 || len > 100)
		return (0);
	return (1);
}

static void	create_map(char **map, int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
}

char	**read_map(char *filename, t_window *game)
{
	int		fd;
	int		lines;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = count_lines(fd);
	if (lines < 3 || lines > 100)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (close(fd), NULL);
	create_map(map, fd);
	if (!map_parsing(map, game))
		return (free_map(map), NULL);
	return (map);
}
