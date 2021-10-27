/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:52:44 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:12:33 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

t_wall	get_param_wall(t_vect pt_h, t_walls walls, double angle)
{
	t_wall	wall;

	if (pt_h.loc.ret == 2)
		wall = walls.sprite;
	else if (angle < 90 || angle > 270)
		wall = walls.wall1;
	else
		wall = walls.wall2;
	return (wall);
}

t_vect	get_dist_min(t_vect pt_h, t_vect pt_v, t_param *param,
		double angle)
{
	double		dist_h;
	double		dist_v;

	dist_v = get_distances(pt_h, pt_v, &dist_h, *param);
	if (dist_h < dist_v)
	{
		param->wall = get_param_wall(pt_h, param->walls, angle);
	}
	else
	{
		if (pt_v.loc.ret == 2)
			param->wall = param->walls.sprite;
		else if (angle > 0 && angle < 180)
			param->wall = param->walls.wall3;
		else
			param->wall = param->walls.wall4;
	}
	if (dist_h < dist_v)
	{
		pt_h.dir = 1;
		return (pt_h);
	}
	pt_v.dir = 0;
	return (pt_v);
}

double	get_distances(t_vect pt_h, t_vect pt_v, double *dist_h,
		t_param param)
{
	double		dist_v;

	*dist_h = sqrt(pow(param.hero.vec.y - pt_h.y, 2)
			+ pow(param.hero.vec.x - pt_h.x, 2));
	dist_v = sqrt(pow(param.hero.vec.y - pt_v.y, 2)
			+ pow(param.hero.vec.x - pt_v.x, 2));
	return (dist_v);
}

t_vect	get_pt_a_90(t_param *param, double angle)
{
	t_vect		pt_a;

	if (angle == 0 || angle == 180)
	{
		if (angle == 0)
			param->wall = param->walls.wall1;
		else
			param->wall = param->walls.wall2;
		pt_a = get_pt_h(*param, param->map, angle);
	}
	else
	{
		if (angle == 90)
			param->wall = param->walls.wall3;
		else
			param->wall = param->walls.wall4;
		pt_a = get_pt_v(*param, param->map, angle);
	}
	return (pt_a);
}
