/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pt_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:41:34 by abrun             #+#    #+#             */
/*   Updated: 2021/01/28 10:42:17 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	is_0_around(t_point pt, char **map, int max_w, int hei)
{
	if ((pt.x - 1 >= 0 && map[pt.y][pt.x - 1] == '0')
			|| (pt.x + 1 < max_w && map[pt.y][pt.x + 1] == '0')
			|| (pt.y - 1 >= 0 && map[pt.y - 1][pt.x] == '0')
			|| (pt.y + 1 < hei && map[pt.y + 1][pt.x] == '0')
			|| (pt.y + 1 < hei && pt.x + 1 < max_w
				&& map[pt.y + 1][pt.x + 1] == '0')
			|| (pt.y - 1 >= 0 && pt.x + 1 < max_w
				&& map[pt.y - 1][pt.x + 1] == '0')
			|| (pt.y - 1 >= 0 && pt.x - 1 >= 0
				&& map[pt.y - 1][pt.x - 1] == '0')
			|| (pt.y + 1 < hei && pt.x - 1 >= 0
				&& map[pt.y + 1][pt.x - 1] == '0'))
		return (1);
	else
		return (0);
}

void	config_right(t_point *pt, t_moves *dir)
{
	dir->up = 1;
	dir->down = 1;
	dir->left = 0;
	pt->x += 1;
}

void	config_up(t_point *pt, t_moves *dir)
{
	dir->left = 1;
	dir->down = 0;
	dir->right = 1;
	pt->y -= 1;
}

void	config_down(t_point *pt, t_moves *dir)
{
	dir->right = 1;
	dir->left = 1;
	dir->up = 0;
	pt->y += 1;
}

void	config_left(t_point *pt, t_moves *dir)
{
	dir->up = 1;
	dir->down = 1;
	dir->right = 0;
	pt->x -= 1;
}
