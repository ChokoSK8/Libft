/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_sprite_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:23:31 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:27:33 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

t_vect	get_inter(t_line d_1, t_line d_2)
{
	t_vect		inter;

	if (d_1.c)
		inter.x = d_1.c;
	else if (d_2.c)
		inter.x = d_2.c;
	else
		inter.x = (d_2.b - d_1.b) / (d_1.a - d_2.a);
	if (d_1.c)
		inter.y = d_2.a * inter.x + d_2.b;
	else
		inter.y = d_1.a * inter.x + d_1.b;
	return (inter);
}

int	is_print(t_vect pt, t_vector end_1, t_vector end_2)
{
	double	d_1;
	double	d_2;

	d_1 = get_dist(end_1, pt);
	d_2 = get_dist(end_2, pt);
	if (d_1 >= 62.000 || d_2 >= 62.000)
		return (0);
	return (1);
}

double	conv_rad(double rad)
{
	double	deg;

	deg = rad * 57.2958;
	return (deg);
}

double	get_angle_sprite(t_vector hero, t_vect cube)
{
	double		angle;

	if (hero.y >= cube.y && hero.x <= cube.x)
		angle = 90 - conv_rad(acos((cube.x - hero.x) / get_dist(hero, cube)));
	else if (hero.y <= cube.y && hero.x <= cube.x)
		angle = 180 - conv_rad(acos((cube.y - hero.y) / get_dist(hero, cube)));
	else if (hero.y >= cube.y && hero.x >= cube.x)
		angle = 360 - conv_rad(acos((hero.y - cube.y) / get_dist(hero, cube)));
	else
		angle = 270 - conv_rad(acos((hero.x - cube.x) / get_dist(hero, cube)));
	return (angle);
}

t_line	get_d_angle_hero(t_player hero, t_map map)
{
	t_line		d;
	t_vect		pt;

	if ((hero.angle > 315 || hero.angle < 45)
		|| (hero.angle > 135 && hero.angle < 225))
		get_pt_a_hori(hero, &pt, map, hero.angle);
	else
		get_pt_a_vert(hero, &pt, map, hero.angle);
	d = get_line_2_pts(pt, hero.vec);
	return (d);
}
