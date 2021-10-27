/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:54:51 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:22:43 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			get_dist_max(t_map map)
{
	if (map.max_width < map.height)
		return (map.len_pix * map.height);
	else
		return (map.max_width * map.len_pix);
}
