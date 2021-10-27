/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:55:36 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:10:42 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			get_color(char *line, t_param *param, int d)
{
	int		*tab;
	int		retur;

	if (!check_color(d, line))
		return (0);
	if (!(tab = get_color_fill_tab(line)))
		return (0);
	if (d == 'F')
	{
		if (!(fill_floor(param, tab)))
			retur = 0;
		else
			retur = 7;
	}
	else
	{
		if (!(fill_roof(param, tab)))
			retur = 0;
		else
			retur = 6;
	}
	free(tab);
	return (retur);
}

int			*get_color_fill_tab(char *line)
{
	int		*tab;

	if (!(tab = malloc(sizeof(int) * 3)))
	{
		ft_putstr_fd("Un malloc a échoué ! \n", 2);
		return (0);
	}
	while (*line && !ft_isdigit(*line))
		line++;
	tab[0] = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	tab[1] = ft_atoi(++line);
	while (*line && *line != ',')
		line++;
	tab[2] = ft_atoi(line++);
	return (tab);
}

int			fill_floor(t_param *param, int *tab)
{
	int		counter;

	counter = 0;
	if (!(param->floor = malloc(sizeof(int) * 3)))
	{
		ft_putstr_fd("Un malloc a échoué ! \n", 2);
		return (0);
	}
	while (counter < 3)
	{
		param->floor[counter] = tab[counter];
		counter++;
	}
	return (1);
}

int			fill_roof(t_param *param, int *tab)
{
	int		counter;

	counter = 0;
	if (!(param->roof = malloc(sizeof(int) * 3)))
	{
		ft_putstr_fd("Un malloc a échoué ! \n", 2);
		return (0);
	}
	while (counter < 3)
	{
		param->roof[counter] = tab[counter];
		counter++;
	}
	return (1);
}
