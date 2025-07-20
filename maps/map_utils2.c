/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:20:02 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/20 18:37:12 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_mur(char **map)
{
	int	i;
	int	len;
	int	lines;

	i = 0;
	len = ft_strlen(map[0]);
	lines = count_true_line(map);
	if (map[0][len - 1] == '\n')
		len--;
	while (i < len)
	{	
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][len - 1] != '1' || map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_rectangle(char **map)
{
	int	i;
	int	len0;
	int	len;

	len0 = ft_strlen(map[0]);
	i = 0;
	if (map[0][len0 - 1] == '\n')
		len0--;
	if (len0 < 3)
		return (0);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len != len0)
			return (0);
		i++;
	}
	return (1);
}
