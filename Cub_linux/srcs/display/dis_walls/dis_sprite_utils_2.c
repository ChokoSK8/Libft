/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_sprite_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:24:16 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:24:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

t_vector	get_end_270(t_vector end_1, t_vector *end_2)
{
	t_vector	end;

	if (end_1.x > end_2->x)
		end = end_1;
	else if (end_1.x != end_2->x)
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	else if (end_1.y > end_2->y)
		end = end_1;
	else
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	return (end);
}

t_vector	get_end_360(t_vector end_1, t_vector *end_2)
{
	t_vector	end;

	if (end_1.x < end_2->x)
		end = end_1;
	else if (end_1.x != end_2->x)
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	else if (end_1.y > end_2->y)
		end = end_1;
	else
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	return (end);
}

t_vector	get_end(t_line d, t_vect cen, double angle, t_vector *end_2)
{
	t_eq		eq;
	t_vector	end_1;
	t_vector	end;

	if (angle != 0.0000 && angle != 90.0000
		&& angle != 180.0000 && angle != 270.0000)
	{
		eq = get_eq_end(d, cen);
		get_ends_end(eq, d, &end_1, end_2);
		if (angle <= 90)
			end = get_end_90(end_1, end_2);
		else if (angle > 90 && angle <= 180)
			end = get_end_180(end_1, end_2);
		else if (angle > 180 && angle <= 270)
			end = get_end_270(end_1, end_2);
		else
			end = get_end_360(end_1, end_2);
	}
	else
		end = get_end_spe(cen, angle, end_2);
	return (end);
}

t_line	get_d_perpendicular(t_line d, t_vect pt)
{
	t_line		d_2;

	if (d.c)
		d_2.a = 0;
	else
		d_2.a = -1.0000 / d.a;
	if (d.a == 0)
		d_2.c = pt.x;
	else
		d_2.c = 0;
	d_2.b = pt.y - d_2.a * pt.x;
	return (d_2);
}

int	get_x_sprite(t_vector pt_1, t_vect pt_2)
{
	double		dist;
	int			x;

	dist = get_dist(pt_1, pt_2) / 2;
	x = round(dist);
	return (x);
}
