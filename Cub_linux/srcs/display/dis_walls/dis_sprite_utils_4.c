/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_sprite_utils_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:25:26 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:25:59 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

t_line	get_line_2_pts(t_vect pt_1, t_vector pt_2)
{
	t_line	d;

	if (round(pt_1.x) == round(pt_2.x))
		d.c = pt_1.x;
	else
	{
		d.c = 0;
		d.a = (pt_1.y - pt_2.y) / (pt_1.x - pt_2.x);
	}
	d.b = pt_1.y - pt_1.x * d.a;
	return (d);
}

double	get_dist(t_vector pt_1, t_vect pt_2)
{
	double		dist;

	dist = sqrt(pow(pt_1.x - pt_2.x, 2) + pow(pt_1.y - pt_2.y, 2));
	return (dist);
}

t_vector	get_end_spe_2(t_vect cube, double angle, t_vector *end_2)
{
	t_vector	end;

	end.x = cube.x;
	end_2->x = cube.x;
	if (angle == 90)
	{
		end.y = cube.y - 32;
		end_2->y = cube.y + 32;
	}
	else
	{
		end.y = cube.y + 32;
		end_2->y = cube.y - 32;
	}
	return (end);
}

t_vector	get_end_spe(t_vect cube, double angle, t_vector *end_2)
{
	t_vector	end;

	if (angle == 0 || angle == 180)
	{
		end.y = cube.y;
		end_2->y = cube.y;
		if (angle == 0)
		{
			end_2->x = cube.x + 32;
			end.x = cube.x - 32;
		}
		else
		{
			end_2->x = cube.x - 32;
			end.x = cube.x + 32;
		}
	}
	else
	{
		end = get_end_spe_2(cube, angle, end_2);
	}
	return (end);
}
