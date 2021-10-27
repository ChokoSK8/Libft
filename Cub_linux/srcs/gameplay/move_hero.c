/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:00:55 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:52:10 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	move_hero(int key, t_param *param)
{
	display_background(*param);
	if (key == 65307)
	{
		free_param(param);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	if (key == 'a')
		move_key_12(&param->hero, param->img_map);
	if (key == 'w')
		move_key_6(&param->hero, param->img_map);
	if (key == 'd')
		param->hero.angle -= 1;
	if (key == 's')
		param->hero.angle += 1;
	if (param->hero.angle < 0)
		param->hero.angle += 360;
	if (param->hero.angle > 360)
		param->hero.angle %= 360;
	display_multi_angle(param, 0xFF);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	return (1);
}

void	move_key_12(t_player *hero, t_img img)
{
	if (!is_wall_12(*hero, img))
	{
		hero->vec.y -= hero->speed
			* cos(convert(hero->angle));
		hero->vec.x -= hero->speed
			* sin(convert(hero->angle));
	}
}

void	move_key_6(t_player *hero, t_img img)
{
	if (!is_wall_6(*hero, img))
	{
		hero->vec.y += hero->speed
			* cos(convert(hero->angle));
		hero->vec.x += hero->speed
			* sin(convert(hero->angle));
	}
}
