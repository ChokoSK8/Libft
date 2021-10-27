/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:58:26 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 11:28:28 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strstr(char *str, char *to_find)
{
	int		counter;
	int		c;

	counter = 0;
	while (str[counter])
	{
		c = 0;
		while (to_find[c] && str[counter + c] &&
			to_find[c] == str[counter + c])
			c++;
		if (!to_find[c])
			return (1);
		counter++;
	}
	return (0);
}
