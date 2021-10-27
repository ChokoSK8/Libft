/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_hori.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:12:05 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 09:44:35 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	get_pt_a_hori(t_player hero, t_vect *pt_a,
						t_map map, double angle)
{
	if (angle > 270 || angle < 90)
	{
		pt_a->y = hero.vec.y - modulo(hero.vec.y, map.len_pix);
		if (pt_a->y == hero.vec.y)
			pt_a->y -= map.len_pix;
		if (angle < 90)
			pt_a->x = hero.vec.x + tan(convert(angle)) * (pt_a->y - hero.vec.y);
		else
			pt_a->x = hero.vec.x + tan(convert(angle)) * (pt_a->y - hero.vec.y);
	}
	else
	{
		pt_a->y = hero.vec.y + (map.len_pix - modulo(hero.vec.y, map.len_pix));
		if (angle < 180)
			pt_a->x = hero.vec.x - tan(convert(180 - angle))
				* (pt_a->y - hero.vec.y);
		else
			pt_a->x = hero.vec.x + tan(convert(angle - 180))
				* (pt_a->y - hero.vec.y);
	}
}

void	get_pt_a_hori_90(t_player hero, t_vect *pt_a, t_map map,
		double angle)
{
	pt_a->x = hero.vec.x;
	if (angle == 0)
	{
		pt_a->y = hero.vec.y - modulo(hero.vec.y, map.len_pix);
		if (pt_a->y == hero.vec.y)
			pt_a->y -= map.len_pix;
	}
	else if (angle == 180)
	{
		pt_a->y = hero.vec.y + (map.len_pix - modulo(hero.vec.y, map.len_pix));
		if (pt_a->y == hero.vec.y)
			pt_a->y += map.len_pix;
	}
}

void	get_vector(double angle, int len_pix, t_vector *vector)
{
	if (angle > 270 || angle < 90)
	{
		vector->y = -len_pix;
		if (angle < 90)
			vector->x = vector->y * tan(convert(angle));
		else
			vector->x = vector->y * tan(convert(angle));
	}
	else
	{
		vector->y = len_pix;
		if (angle < 180)
			vector->x = -vector->y * tan(convert(180 - angle));
		else
			vector->x = vector->y * tan(convert(angle - 180));
	}
}

t_loc	is_wall_horizontal(t_vect pt, double angle, t_param param)
{
	t_loc	loc;

	loc.ret = -1;
	if (angle > 270 || angle < 90)
		loc.y = (pt.y / param.map.len_pix) - 1;
	else
		loc.y = pt.y / param.map.len_pix;
	if (angle > 180)
		loc.x = pt.x / param.map.len_pix;
	else
		loc.x = pt.x / param.map.len_pix;
	if ((loc.x < param.map.max_width && loc.x >= 0)
		&& (loc.y < param.map.height && loc.y >= 0))
	{
		if (param.map.map[loc.y][loc.x] == '1')
			loc.ret = 1;
		else if (param.map.map[loc.y][loc.x] == '2')
			loc.ret = 2;
	}
	else
		loc.ret = 1;
	if (loc.ret < 0)
		loc.ret = 0;
	return (loc);
}

t_vect	get_pt_h(t_param param, t_map map, double angle)
{
	t_vect		pt_a;
	t_vector	vector;
	t_loc		loc;

	loc.ret = 0;
	if (angle == 0 || angle == 180)
		get_pt_a_hori_90(param.hero, &pt_a, map, angle);
	else
		get_pt_a_hori(param.hero, &pt_a, map, angle);
	get_vector(angle, map.len_pix, &vector);
	loc = is_wall_horizontal(pt_a, angle, param);
	if (loc.ret == 2 && !is_print_dist(loc, param.hero.vec, pt_a, param))
		loc.ret = 0;
	while (!loc.ret)
	{
		pt_a.x += vector.x;
		pt_a.y += vector.y;
		loc = is_wall_horizontal(pt_a, angle, param);
		if (loc.ret == 2 && !is_print_dist(loc, param.hero.vec, pt_a, param))
			loc.ret = 0;
	}
	pt_a.loc = loc;
	return (pt_a);
}
