/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:06:40 by abrun             #+#    #+#             */
/*   Updated: 2021/01/25 17:23:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	display_background(t_param param)
{
	display_roof(param, param.height, param.width, param.img.size_line);
	display_floor(param, param.height, param.width, param.img.size_line);
}

void	display_floor(t_param param, int height,
			int width, int size_line)
{
	int		x;
	int		y;
	int		pos;

	x = 0;
	while (x < width)
	{
		y = height / 2;
		while (y < height)
		{
			pos = x * 4 + size_line * y;
			param.img.data[pos] = param.floor[2];
			param.img.data[pos + 1] = param.floor[1];
			param.img.data[pos + 2] = param.floor[0];
			y++;
		}
		x++;
	}
}

void	display_roof(t_param param, int height,
			int width, int size_line)
{
	int		x;
	int		y;
	int		pos;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height / 2)
		{
			pos = x * 4 + size_line * y;
			param.img.data[pos] = param.roof[2];
			param.img.data[pos + 1] = param.roof[1];
			param.img.data[pos + 2] = param.roof[0];
			y++;
		}
		x++;
	}
}
