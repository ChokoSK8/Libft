/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:09:52 by abrun             #+#    #+#             */
/*   Updated: 2021/03/25 14:23:57 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

long int		ft_strstr_conv(char *str, char to_find)
{
	long int		counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == to_find)
			return (counter);
		else
			counter++;
	}
	return (-1);
}

bool			ft_checkbase(char *base)
{
	unsigned int baselen;
	unsigned int n;
	unsigned int counter;

	baselen = ft_len(base);
	if (baselen <= 1)
		return (false);
	n = 0;
	while (base[n])
	{
		if (base[n] == ' ' || (base[n] >= 9 && base[n] <= 13)
				|| base[n] == '+' || base[n] == '-')
			return (false);
		counter = n + 1;
		while (base[counter])
		{
			if (base[counter] == base[n])
				return (false);
			counter++;
		}
		n++;
	}
	return (true);
}

long int		ft_atoi_base(char *str, char *base)
{
	long int		nbr;
	unsigned int	n_minus;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	n_minus = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n_minus++;
		str++;
	}
	nbr = 0;
	while (*str && ft_strstr_conv(base, *(str)) != -1)
	{
		nbr += ft_strstr_conv(base, *str);
		nbr *= ft_len(base);
		str++;
	}
	nbr /= ft_len(base);
	n_minus % 2 ? nbr *= -1 : nbr;
	return (nbr);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int		n;
	int				size;
	unsigned int	base_len;
	char			*res;
	long int		tab_c_p[2];

	if (!ft_checkbase(base_from) || !ft_checkbase(base_to))
		return (0);
	n = ft_atoi_base(nbr, base_from);
	base_len = ft_len(base_to);
	tab_c_p[0] = 0;
	if (n < 0)
	{
		tab_c_p[0]++;
		n *= -1;
	}
	size = ft_put_puissance_conv(n, base_len) + 1 + tab_c_p[0];
	if (!(res = (char *)malloc(sizeof(char) * size)))
		return (0);
	if (size == 0)
		return (0);
	tab_c_p[1] = size - 1 - tab_c_p[0];
	res = ft_putnbr_base_conv(n, base_to, size, tab_c_p);
	return (res);
}
