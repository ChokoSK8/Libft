/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_vert_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:11:36 by abrun             #+#    #+#             */
/*   Updated: 2021/01/26 16:11:40 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_x(t_vect pt, double angle, t_param param)
{
	int		x;

	if (angle > 180)
		x = (pt.x + 0.0001) / param.map.len_pix;
	else
		x = pt.x / param.map.len_pix - 1;
	return (x);
}
