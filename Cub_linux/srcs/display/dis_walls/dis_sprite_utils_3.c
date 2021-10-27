/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_sprite_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:24:49 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:25:20 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void	change_end_2(t_vector *end_2, t_vector end_1)
{
	end_2->x = end_1.x;
	end_2->y = end_1.y;
}

t_eq	get_eq_end(t_line d, t_vect cen)
{
	t_eq	eq;

	eq.a = 1 + pow(d.a, 2);
	eq.b = -2 * cen.x - 2 * d.a * cen.y + 2 * d.a * d.b;
	eq.c = -1024 + pow(cen.x, 2) - 2 * cen.y * d.b
		+ pow(cen.y, 2) + pow(d.b, 2);
	eq.d = pow(eq.b, 2) - 4 * eq.a * eq.c;
	return (eq);
}

void	get_ends_end(t_eq eq, t_line d,
			t_vector *end_1, t_vector *end_2)
{
	end_1->x = (-eq.b - sqrt(eq.d)) / (2 * eq.a);
	end_2->x = (-eq.b + sqrt(eq.d)) / (2 * eq.a);
	end_1->y = d.a * end_1->x + d.b;
	end_2->y = d.a * end_2->x + d.b;
}

t_vector	get_end_90(t_vector end_1, t_vector *end_2)
{
	t_vector	end;

	if (round(end_1.x) < round(end_2->x))
		end = end_1;
	else if (round(end_1.x) != round(end_2->x))
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	else if (round(end_1.y) < round(end_2->y))
		end = end_1;
	else
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	return (end);
}

t_vector	get_end_180(t_vector end_1, t_vector *end_2)
{
	t_vector	end;

	if (round(end_1.x) > round(end_2->x))
		end = end_1;
	else if (round(end_1.x) != round(end_2->x))
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	else if (round(end_1.y) < round(end_2->y))
		end = end_1;
	else
	{
		end = *end_2;
		change_end_2(end_2, end_1);
	}
	return (end);
}
