/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:22:30 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:23:22 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

t_vect	init_sp_cube_n(double *n, t_loc *sp, t_vect pt, t_param *param)
{
	t_vect		cube;

	sp->x = pt.loc.x;
	sp->y = pt.loc.y;
	*n = 30 / (double)param->width;
	cube.x = (pt.loc.x + 0.5) * param->map.len_pix;
	cube.y = (pt.loc.y + 0.5) * param->map.len_pix;
	return (cube);
}

double	init_angle_ds(t_lines *ds, t_vect cube, t_param *param)
{
	double		angle;

	ds->d = get_line_2_pts(cube, param->hero.vec);
	ds->d_2 = get_d_perpendicular(ds->d, cube);
	angle = get_angle_sprite(param->hero.vec, cube);
	return (angle);
}

t_vect	get_pt_sprite(double angle, t_param param, t_map map)
{
	t_vect		pt;

	if (angle != 0 && angle != 90 && angle != 180 && angle != 270)
		pt = get_dist_min(get_pt_h(param, map, angle),
				get_pt_v(param, map, angle), &param, angle);
	else
		pt = get_pt_a_90(&param, angle);
	return (pt);
}

int	loop_cond(int n_wall, int width, t_loc loc, t_loc sp)
{
	if (n_wall < width && loc.ret == 2
		&& loc.x == sp.x && loc.y == sp.y)
		return (1);
	return (0);
}

double	display_sprite(int *n_wall, t_param *param,
			double counter, t_vect pt)
{
	t_vectors	ends;
	t_lines		ds;
	t_vect		cube;
	double		tab[3];
	t_loc		sp;

	cube = init_sp_cube_n(&tab[1], &sp, pt, param);
	tab[0] = init_angle_ds(&ds, cube, param);
	ends.v = get_end(ds.d_2, cube, tab[0], &ends.v_2);
	while (loop_cond(*n_wall, param->width, pt.loc, sp))
	{
		tab[0] = get_angle_right(param->hero.angle, counter);
		ds.d = get_line_2_pts(pt, param->hero.vec);
		pt = get_inter(ds.d, ds.d_2);
		tab[2] = get_d(param->hero, pt, counter);
		param->wall = param->walls.sprite;
		get_dim(&param->wall, tab[2], param, tab[0]);
		param->x = get_x_sprite(ends.v, pt);
		if (is_print(pt, ends.v, ends.v_2))
			draw_wall(param->wall, *n_wall, param, 0xFF);
		*n_wall += 1;
		counter -= tab[1];
		pt = get_pt_sprite(tab[0], *param, param->map);
	}
	return (counter);
}
