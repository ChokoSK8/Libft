/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:32:59 by abrun             #+#    #+#             */
/*   Updated: 2021/03/25 14:33:59 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		fill_len_fic(char *header, t_param param)
{
	int		len;
	char	*conv;
	int		c;

	c = get_c(param.width);
	len = 54 + (param.width * 3 + c) * param.height;
	printf("len : %d\n", len);
	conv = putnbr_base(len, "0123456789", 8);
	put_conv_in(conv, header, 8, 2);
	header[10] = 0;
}

void		fill_chp_res(char *header)
{
	int		i;

	i = 10;
	while (i < 18)
	{
		header[i] = '0';
		i++;
	}
	header[i] = 0;
}

void		fill_offset(char *header)
{
	int		i;

	i = 18;
	header[i++] = 3 + '0';
	header[i++] = 6 + '0';
	while (i < 26)
	{
		header[i] = '0';
		i++;
	}
	header[i] = 0;
}

void		fill_len_img(char *header)
{
	int		i;

	i = 26;
	header[i++] = 2 + '0';
	header[i++] = 8 + '0';
	while (i < 34)
	{
		header[i] = '0';
		i++;
	}
	header[i] = 0;
}

int			ft_put_pui_save(int nbr, int base_len)
{
	int			res;
	int			puissance;

	puissance = 0;
	res = base_len;
	while (nbr >= res)
	{
		puissance++;
		res *= base_len;
	}
	return (puissance + 1);
}
