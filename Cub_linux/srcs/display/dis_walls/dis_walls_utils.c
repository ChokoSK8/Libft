/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_walls_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:46:48 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:11:22 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

double	get_angle_right(int angle_h, double counter)
{
	double	angle;

	angle = angle_h + counter;
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle = 360 + angle;
	return (angle);
}

void	get_dim(t_wall *wall, double dist, t_param *param, double angle)
{
	wall->width = 1;
	wall->height = (param->height / dist) * 60;
	wall->coef = (double)wall->img.height / (double)wall->height;
	wall->angle = angle / 0.05;
}

double	get_d(t_player hero, t_vect pt_a, double counter)
{
	double	dist;

	dist = sqrt(pow(hero.vec.x - pt_a.x, 2)
			+ pow(hero.vec.y - pt_a.y, 2)) * cos(convert(counter));
	return (dist);
}
