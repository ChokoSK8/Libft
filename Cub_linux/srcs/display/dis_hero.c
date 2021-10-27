/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_hero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:59:56 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 11:03:19 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	change_hero_pos(t_param param, int color)
{
	int		x;
	int		y;
	int		c;
	int		pos;

	y = 0;
	while (y < param.hero.len)
	{
		x = 0;
		while (x < param.hero.len)
		{
			c = 0;
			while (c < 4)
			{
				pos = ((int)param.hero.vec.x - x) * 4 + (param.img_map.size_line
						* ((int)param.hero.vec.y - y)) + c;
				if (color)
					color -= 10;
				param.img_map.data[pos] = color;
				c++;
			}
			x++;
		}
		y++;
	}
}
