/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:43:32 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 09:46:48 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	is_printable(t_vect pt, t_vector end_1,
			t_vector end_2, t_vect pt_a)
{
	double	d_1;
	double	d_2;
	double	dist;

	dist = sqrt(pow(pt_a.x - pt.x, 2) + pow(pt_a.y - pt.y, 2));
	if (dist < 2)
		return (0);
	d_1 = get_dist(end_1, pt);
	d_2 = get_dist(end_2, pt);
	if (d_1 >= 62.000 || d_2 >= 62.000)
		return (0);
	return (1);
}

int	is_print_dist(t_loc loc, t_vector hero,
			t_vect pt, t_param param)
{
	t_vect		cube;
	double		angle;
	t_vectors	ends;
	t_lines		ds;
	t_vect		pt_b;

	cube.x = (loc.x + 0.5) * param.map.len_pix;
	cube.y = (loc.y + 0.5) * param.map.len_pix;
	ds.d = get_line_2_pts(cube, hero);
	ds.d_2 = get_d_perpendicular(ds.d, cube);
	angle = get_angle_sprite(hero, cube);
	ends.v = get_end(ds.d_2, cube, angle, &ends.v_2);
	ds.d = get_line_2_pts(pt, hero);
	pt_b = get_inter(ds.d, ds.d_2);
	if (is_printable(pt_b, ends.v, ends.v_2, pt))
		return (1);
	return (0);
}

double	modulo(double x, int a)
{
	double	dec;
	double	mod;

	dec = x - (int)x;
	mod = (int)x % a;
	mod += dec;
	return (mod);
}

int	get_loc_y(double angle, t_vect pt, t_param param)
{
	int	loc_y;
	int	pt_y;

	pt_y = (int)pt.y;
	if (angle < 90 || angle > 270)
	{
		if (!(pt.y - (double)pt_y) && !((int)pt.y % param.map.len_pix))
			loc_y = pt.y / param.map.len_pix - 1;
		else
			loc_y = pt.y / param.map.len_pix;
	}
	else
		loc_y = pt.y / param.map.len_pix;
	return (loc_y);
}

double	convert(double degre)
{
	double	rad;

	rad = degre / 57.2958;
	return (rad);
}
