/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:38:09 by abrun             #+#    #+#             */
/*   Updated: 2021/03/09 16:05:31 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		init_sprite_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.sp,
			&wall->img.width, &wall->img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void		init_wall4_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.so,
			&wall->img.width, &wall->img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void		init_wall3_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.ea,
			&wall->img.width, &wall->img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void		init_wall2_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.we,
			&wall->img.width, &wall->img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void		init_wall1_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.no,
			&wall->img.width, &wall->img.height);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}
