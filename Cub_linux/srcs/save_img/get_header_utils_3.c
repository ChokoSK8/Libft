/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:35:29 by abrun             #+#    #+#             */
/*   Updated: 2021/03/25 14:36:07 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			convert_hexa(char *header, int i)
{
	int		a;
	int		b;
	int		res;

	if (header[i] >= 96)
		a = header[i] - 87;
	else
		a = header[i] - 48;
	if (header[i + 1] >= 96)
		b = header[i + 1] - 87;
	else
		b = header[i + 1] - 48;
	res = a * 16 + b;
	return (res);
}

void		get_resu(char *header, char *res)
{
	int		i;
	int		j;

	i = 2;
	j = 2;
	res[0] = 'B';
	res[1] = 'M';
	while (header[i])
	{
		res[j] = convert_hexa(header, i);
		i += 2;
		j++;
	}
}

int			get_save_len(t_param param)
{
	int		len;

	len = 54 + param.height * ((param.width * 3) + get_c(param.width));
	return (len);
}
