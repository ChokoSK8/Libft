/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:55:20 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:35:01 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*int			destroy_win(int key, t_param *param)
  {
  (void)param;
  printf("key : %d\n", key);
  return (1);
  }*/

int	is_save(char *s)
{
	if (s[0] == '-' && s[1] == '-' && s[2] == 's'
		&& s[3] == 'a' && s[4] == 'v' && s[5] == 'e')
		return (1);
	return (0);
}

void	save_img(t_param param)
{
	int		fd;
	int		i;
	int		end;

	get_header(&param);
	get_pix(param.img.data, &param, param.img.size_line);
	fd = open("image.bmp", O_WRONLY | O_CREAT);
	end = (param.width * 3 + get_c(param.width)) * param.height + 54;
	printf("end : %d\n", end);
	i = 0;
	while (i < end)
	{
		write(fd, &param.save[i], 1);
		i++;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_param		param;

	if (ac < 2)
		ft_putstr_fd("Il n'y pas de *.cub passé en argument !\n", 2);
	if (av[1])
		param.cub = av[1];
	if (!init_param(&param))
		return (0);
	param.img_map.image = mlx_new_image(param.mlx,
			param.map.max_width * param.map.len_pix,
			param.map.height * param.map.len_pix);
	param.img_map.data = mlx_get_data_addr(param.img_map.image,
			&param.img_map.bpp, &param.img_map.size_line,
			&param.img_map.endian);
	display_map(param.map, param);
	display_background(param);
	display_multi_angle(&param, 0xFF);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	if (ac >= 3 && is_save(av[2]))
		save_img(param);
	mlx_hook(param.win, 2, 1L << 0, move_hero, &param);
	//	mlx_hook(param.win, 2, 1L << 2, destroy_win, &param);
	mlx_loop(param.mlx);
	return (0);
}
