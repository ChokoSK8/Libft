/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:23:18 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:57:42 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		free_param(t_param *param)
{
	int		counter;

	counter = 0;
	free(param->no);
	free(param->sp);
	free(param->so);
	free(param->ea);
	free(param->we);
	free(param->floor);
	free(param->roof);
	mlx_destroy_image(param->mlx, param->img_map.image);
	mlx_destroy_image(param->mlx, param->img.image);
	mlx_destroy_image(param->mlx, param->walls.wall1.img.image);
	mlx_destroy_image(param->mlx, param->walls.wall2.img.image);
	mlx_destroy_image(param->mlx, param->walls.wall3.img.image);
	mlx_destroy_image(param->mlx, param->walls.wall4.img.image);
	mlx_destroy_image(param->mlx, param->walls.sprite.img.image);
	while (param->map.map[counter])
		free(param->map.map[counter++]);
	free(param->map.map);
}

void		free_tab_checks(t_param *param)
{
	if (param->checks[0] == 1)
		free(param->no);
	if (param->checks[1] == 1)
		free(param->so);
	if (param->checks[2] == 1)
		free(param->ea);
	if (param->checks[3] == 1)
		free(param->we);
	if (param->checks[5] == 1)
		free(param->roof);
	if (param->checks[6] == 1)
		free(param->floor);
	if (param->checks[7] == 1)
		free(param->sp);
	free(param->tab);
}

void		free_map_param(t_param *param)
{
	int		counter;

	counter = 0;
	free(param->no);
	free(param->sp);
	free(param->so);
	free(param->ea);
	free(param->we);
	free(param->floor);
	free(param->roof);
	while (param->map.map[counter])
		free(param->map.map[counter++]);
	mlx_destroy_display(param->mlx);
}

void		free_in_loop(t_param *param, int i, char **map)
{
	free_tab_checks(param);
	while (i--)
		free(map[i]);
	free(map);
}
