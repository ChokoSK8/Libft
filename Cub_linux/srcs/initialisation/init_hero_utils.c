/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hero_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:38:54 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 17:26:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

t_point	get_pos_hero(t_map map)
{
	t_point		pt;

	pt.y = 0;
	while (pt.y < map.height)
	{
		pt.x = 0;
		while (map.map[pt.y][pt.x])
		{
			if (map.map[pt.y][pt.x] == map.dir)
				return (pt);
			pt.x += 1;
		}
		pt.y += 1;
	}
	return (pt);
}

int	get_angle(t_map map)
{
	if (map.dir == 'N')
		return (0);
	else if (map.dir == 'E')
		return (270);
	else if (map.dir == 'S')
		return (180);
	else
		return (90);
}

int	get_dir(t_map map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] >= 'A' && map.map[y][x] <= 'Z')
				return (map.map[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}
