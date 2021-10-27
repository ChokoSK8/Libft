/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:25:02 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:50:34 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

t_point	get_hero(char **map)
{
	t_point	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] >= 'A' && map[p.y][p.x] <= 'Z')
				return (p);
			p.x += 1;
		}
		p.y += 1;
	}
	return (p);
}

void	get_pt_start(t_point *pt, char **map)
{
	int		y;

	y = pt->y;
	while (map[y][pt->x] != '1')
		y--;
	pt->y = y;
}

int	check_around(t_point pt, t_map map)
{
	t_point		end;
	t_moves		dir;

	dir.right = 1;
	dir.left = 1;
	dir.up = 1;
	dir.down = 1;
	end.x = pt.x;
	end.y = 0;
	end.init = 0;
	if (!(move_pt(&pt, map, &end, &dir)))
		return (0);
	while (pt.x != end.x || pt.y != end.y)
	{
		if (!(move_pt(&pt, map, &end, &dir)))
			return (0);
	}
	return (1);
}
