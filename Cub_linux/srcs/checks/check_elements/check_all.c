/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:45:11 by abrun             #+#    #+#             */
/*   Updated: 2021/03/24 12:16:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	check_all(int *checks, t_param *param)
{
	int		counter;

	counter = 0;
	while (counter < 8)
	{
		if (checks[counter] != 1)
		{
			ft_putstr_fd("Il n'y a pas tous les éléments !\n", 1);
			free_tab_checks(param);
			return (0);
		}
		counter++;
	}
	return (1);
}
