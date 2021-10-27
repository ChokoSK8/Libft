/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:02:19 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 17:43:20 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	is_wall_around(t_player hero, t_img img)
{
	int		x;
	int		y;
	int		x_final;
	int		y_final;
	int		pos;

	y = (int)hero.vec.y - 2;
	x_final = (int)hero.vec.x + 2;
	y_final = (int)hero.vec.y + 2;
	while (y < y_final)
	{
		x = (int)hero.vec.x - 2;
		while (x < x_final)
		{
			pos = x * 4 + img.size_line * y;
			if (img.data[pos])
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_wall_12(t_player hero, t_img img_map)
{
	hero.vec.y -= round(hero.speed * cos(convert(hero.angle)));
	hero.vec.x -= round(hero.speed * sin(convert(hero.angle)));
	if (is_wall_around(hero, img_map))
		return (1);
	return (0);
}

int	is_wall_6(t_player hero, t_img img_map)
{
	hero.vec.y += round(hero.speed * cos(convert(hero.angle)));
	hero.vec.x += round(hero.speed * sin(convert(hero.angle)));
	if (is_wall_around(hero, img_map))
		return (1);
	return (0);
}
