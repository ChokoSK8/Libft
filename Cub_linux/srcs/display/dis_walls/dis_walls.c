/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:43:55 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:27:15 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void	get_param_x(t_param *param, t_vect pt_a)
{
	if (pt_a.dir == 1)
		param->x = ((int)round(pt_a.x) % param->map.len_pix)
			% param->wall.img.width;
	else
		param->x = ((int)round(pt_a.y) % param->map.len_pix)
			% param->wall.img.width;
}

static t_vect	get_pt_a_dist(t_param *param, double angle)
{
	t_vect		pt_a;

	if (angle != 0 && angle != 90 && angle != 180 && angle != 270)
		pt_a = get_dist_min(get_pt_h(*param, param->map, angle),
				get_pt_v(*param, param->map, angle), param, angle);
	else
		pt_a = get_pt_a_90(param, angle);
	return (pt_a);
}

void	display_multi_angle(t_param *param, int color)
{
	double			c;
	t_vect			pt_a;
	double			n;
	int				n_wall;
	double			angle;

	n = 30 / (double)param->width;
	angle = 0;
	n_wall = 0;
	c = 15;
	while (n_wall < param->width)
	{
		angle = get_angle_right(param->hero.angle, c);
		pt_a = get_pt_a_dist(param, angle);
		if (pt_a.loc.ret == 2)
			c = display_sprite(&n_wall, param, c, pt_a);
		else
		{
			get_param_x(param, pt_a);
			get_dim(&param->wall, get_d(param->hero, pt_a, c), param, angle);
			draw_wall(param->wall, n_wall, param, color);
			n_wall++;
			c -= n;
		}
	}
}

void	draw_wall(t_wall wall, int pos_x, t_param *param, int color)
{
	int			y;
	int			pos;
	int			start_y;

	y = 0;
	start_y = (param->height - wall.height) / 2;
	if (color)
	{
		dis_textures(wall, param, pos_x);
	}
	else
	{
		while (y < wall.height)
		{
			pos = (pos_x * 4) + (param->img.size_line * (start_y + y));
			if (start_y + y >= 0 && start_y + y < param->height)
			{
				param->img.data[pos] = color;
				param->img.data[pos + 1] = color;
				param->img.data[pos + 2] = color;
			}
			y++;
		}
	}
}

void	dis_textures(t_wall wall, t_param *param, int pos_x)
{
	int			y;
	int			start_y;
	int			pos;
	int			pos_2;
	double		y_2;

	y_2 = 0;
	y = 0;
	start_y = (param->height - wall.height) / 2;
	while (y < wall.height)
	{
		if (start_y + y >= 0 && start_y + y < param->height)
		{
			pos = (pos_x % param->width * 4)
				+ (param->img.size_line * (start_y + y));
			pos_2 = (param->x * 4)
				+ (wall.img.size_line * ((int)y_2 % wall.img.height));
			param->img.data[pos] = param->wall.img.data[pos_2];
			param->img.data[pos + 1] = param->wall.img.data[pos_2 + 1];
			param->img.data[pos + 2] = param->wall.img.data[pos_2 + 2];
		}
		y_2 += wall.coef;
		y++;
	}
}
