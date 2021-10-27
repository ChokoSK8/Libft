/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:12:28 by abrun             #+#    #+#             */
/*   Updated: 2021/03/23 14:06:21 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

long int	ft_pow_conv(long int nb, int power)
{
	long int res;

	res = 1;
	while (power-- > 0)
		res *= nb;
	return (res);
}

int			ft_len(char *str)
{
	int strlen;

	strlen = 0;
	while (*str++)
		strlen++;
	return (strlen);
}

long int	ft_put_puissance_conv(long int nbr, unsigned int base_len)
{
	long int	res;
	long int	puissance;

	puissance = 0;
	res = base_len;
	while (nbr >= res)
	{
		puissance++;
		res *= base_len;
	}
	return (puissance);
}

char		*ft_putnbr_base_conv(long int nbr, char *base, int size, long int tab[2])
{
	int				base_len;
	char			*res;

	if (!(res = (char *)malloc(sizeof(char) * size--)))
		return (0);
	base_len = ft_len(base);
	if (tab[0])
		res[0] = '-';
	while (nbr > 0)
	{
		res[tab[0]] = base[nbr / ft_pow_conv(base_len, tab[1])];
		tab[0]++;
		nbr %= ft_pow_conv(base_len, tab[1]);
		tab[1]--;
	}
	while (tab[1]-- >= 0)
	{
		res[tab[0]] = base[0];
		tab[0]++;
	}
	return (res);
}
