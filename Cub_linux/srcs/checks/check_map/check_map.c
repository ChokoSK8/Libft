/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:35:41 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:52:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	is_pos_hero(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' ||
				map[y][x] == 'S' || map[y][x] == 'W')
				return (1);
			x++;
		}
		y++;
	}
	ft_putstr_fd("Il n'y a pas de répère pour le héro !\n", 2);
	return (0);
}

int	is_surrounded(t_map map)
{
	t_point		pt;

	pt = get_hero(map.map);
	get_pt_start(&pt, map.map);
	if (!check_around(pt, map))
		return (0);
	return (1);
}

int	is_characters_ok(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'N' && map[y][x] != 'E'
				&& map[y][x] != 'S' && map[y][x] != 'W'
				&& map[y][x] != '2' && map[y][x] != '1'
				&& map[y][x] != 32 && map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
