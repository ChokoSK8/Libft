/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:30:45 by abrun             #+#    #+#             */
/*   Updated: 2021/03/25 14:31:43 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		fill_comp(char *header)
{
	int		i;

	i = 58;
	while (i < 66)
		header[i++] = '0';
	header[i] = 0;
}

void		fill_n_oct(char *header)
{
	int		i;

	i = 66;
	while (i < 74)
		header[i++] = '0';
}

void		fill_wid_hei(char *header, t_param param)
{
	char	*conv;

	conv = putnbr_base(param.width, "0123456789", 8);
	put_conv_in(conv, header, 8, 34);
	conv = putnbr_base(param.height, "0123456789", 8);
	put_conv_in(conv, header, 8, 42);
}

void		fill_n_plan(char *header)
{
	int		i;

	i = 50;
	header[i++] = '0';
	header[i++] = '1';
	header[i++] = '0';
	header[i++] = '0';
	header[i] = 0;
}

void		fill_bit_per_pix(char *header)
{
	int		i;

	i = 54;
	header[i++] = '1';
	header[i++] = '8';
	header[i++] = '0';
	header[i++] = '0';
	header[i] = 0;
}
