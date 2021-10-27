/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:11:37 by abrun             #+#    #+#             */
/*   Updated: 2021/03/25 14:36:46 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void		get_header(t_param *param)
{
	char	*header;
	int		i;

	if (!(header = malloc(110)))
		param->save = NULL;
	if (!(param->save = malloc(get_save_len(*param))))
		param->save = NULL;
	header[0] = 'B';
	header[1] = 'M';
	fill_len_fic(header, *param);
	fill_chp_res(header);
	fill_offset(header);
	fill_len_img(header);
	fill_wid_hei(header, *param);
	fill_n_plan(header);
	fill_bit_per_pix(header);
	fill_comp(header);
	fill_n_oct(header);
	i = 74;
	while (i < 106)
		header[i++] = '0';
	header[i] = 0;
	get_resu(header, param->save);
	free(header);
}

void		put_zero(char *s)
{
	int		len;
	char	tmp;

	len = ft_len(s);
	s[len] = '0';
	while (len > 0)
	{
		tmp = s[len];
		s[len] = s[len - 1];
		s[len - 1] = tmp;
		len--;
	}
}

char		*putnbr_base(int nbr, char *base, int size)
{
	char		*res;
	int			len;
	char		n[size + 1];
	int			i;

	i = 0;
	len = ft_put_pui_save(nbr, 10);
	while (i < len)
	{
		n[i] = nbr / pow(10, len - i - 1) + '0';
		nbr = (nbr % (int)pow(10, len - i - 1));
		i++;
	}
	n[i] = 0;
	res = ft_convert_base(n, base, "0123456789abcdef");
	i = ft_len(res);
	if (i % 2 != 0)
	{
		put_zero(res);
		i++;
	}
	while (i < size)
		res[i++] = '0';
	res[i] = 0;
	return (res);
}

void		put_conv_in(char *conv, char *header, int con_len, int j)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (i < con_len)
	{
		if (conv[i] == '0' && conv[i + 1] == '0')
			i = con_len;
		else
		{
			len++;
			i += 2;
		}
	}
	len = len * 2 - 1;
	i = j;
	while (len > 0)
	{
		header[j++] = conv[len - 1];
		header[j++] = conv[len];
		len -= 2;
	}
	while (j < i + con_len)
		header[j++] = '0';
}
