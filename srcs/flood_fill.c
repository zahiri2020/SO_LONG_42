/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:29:38 by ezahiri           #+#    #+#             */
/*   Updated: 2024/05/05 13:26:43 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		map[y][x] = '1';
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		flood_fill(map, y - 1, x);
		flood_fill(map, y + 1, x);
		flood_fill(map, y, x - 1);
		flood_fill(map, y, x + 1);
	}
}

int	check_ff(char **map, int y, int x)
{
	flood_fill(map, y, x);
	if (ft_count(map, 'E') != 0)
	{
		memfree(map);
		ft_putstr_fd("Error\nplayer can't reach to exit", 2);
		return (0);
	}
	else if (ft_count(map, 'C') != 0)
	{
		memfree(map);
		ft_putstr_fd ("Error\nplayer can't reach to collecteble", 2);
		return (0);
	}
	memfree(map);
	return (1);
}
