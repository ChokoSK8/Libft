/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:13:36 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 15:15:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcpy(char *dest, char *src)
{
	int		counter;

	counter = 0;
	while (*src)
		dest[counter++] = *src++;
	return (counter);
}
