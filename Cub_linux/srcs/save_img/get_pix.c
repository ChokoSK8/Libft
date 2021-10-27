/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:58:01 by abrun             #+#    #+#             */
/*   Updated: 2021/03/26 10:56:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			get_c(int wid)
{
	int		n;
	int		c;

	n = (3 * wid) / 4;
	if (((3 * wid) % 4) != 0)
		n++;
	c = 4 * n - 3 * wid;
	return (c);
}

void		init_cyj(int *j, int *c, int *y, t_param *param)
{
	*c = get_c(param->width);
	*y = param->height - 1;
	*j = 54;
}

void		get_pix(char *data, t_param *param, int size_line)
{
	int			y;
	int			x;
	int			c;
	int			i;
	int			j;

	init_cyj(&j, &c, &y, param);
	while (y >= 0)
	{
		x = 0;
		while (x < param->width)
		{
			i = ((x * 4) + size_line * y);
			param->save[j++] = data[i];
			param->save[j++] = data[i + 1];
			param->save[j++] = data[i + 2];
			x++;
		}
		x = 0;
		while (x++ < c)
			param->save[j++] = 0;
		y--;
	}
}
