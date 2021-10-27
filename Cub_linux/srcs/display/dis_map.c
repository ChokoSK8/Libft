/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:57:31 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:32:16 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	display_map(t_map map, t_param param)
{
	t_point		img_pt;
	t_point		map_pt;

	img_pt.y = 0;
	img_pt.x = 0;
	map_pt.x = 0;
	while (map_pt.x < map.height)
	{
		map_pt.y = 0;
		while (map.map[map_pt.x][map_pt.y])
		{
			if (map.map[map_pt.x][map_pt.y] == '1'
					|| map.map[map_pt.x][map_pt.y] == '2')
				display_map_case(map, img_pt, param);
			map_pt.y += 1;
			img_pt.x += map.len_pix;
		}
		map_pt.x += 1;
		img_pt.x -= (map_pt.y * map.len_pix);
		img_pt.y += map.len_pix;
	}
}

void	display_map_case(t_map map, t_point img_pt, t_param param)
{
	int		pos;
	int		x_bis;
	int		y_bis;

	y_bis = map.len_pix;
	while (y_bis--)
	{
		x_bis = map.len_pix;
		while (x_bis--)
		{
			pos = (img_pt.x * 4) + (param.img_map.size_line * img_pt.y);
			param.img_map.data[pos] = 100;
			param.img_map.data[pos + 1] = 20;
			param.img_map.data[pos + 2] = -100;
			param.img_map.data[pos + 3] = 10;
			img_pt.x += 1;
		}
		img_pt.x -= map.len_pix;
		img_pt.y += 1;
	}
}

void	display_map_empty_case(t_map map, t_point img_pt, t_param param)
{
	int		pos;
	int		x_bis;
	int		y_bis;

	y_bis = map.len_pix;
	while (y_bis--)
	{
		x_bis = map.len_pix;
		while (x_bis--)
		{
			pos = (img_pt.x * 4) + (param.img_map.size_line * img_pt.y);
			if (y_bis == map.len_pix - 1 || x_bis == map.len_pix - 1)
			{
				param.img_map.data[pos] = 0;
				param.img_map.data[pos + 1] = 0;
				param.img_map.data[pos + 2] = 0;
				param.img_map.data[pos + 3] = 0;
			}
			img_pt.x += 1;
		}
		img_pt.x -= map.len_pix;
		img_pt.y += 1;
	}
}
