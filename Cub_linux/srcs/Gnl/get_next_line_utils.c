/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:20:05 by abrun             #+#    #+#             */
/*   Updated: 2021/01/21 10:38:26 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_new_buf(char *buf)
{
	size_t		buf_len;
	size_t		buf_n_len;
	char		*new_buf;
	int			counter;

	counter = 0;
	buf_len = ft_strlen(buf);
	buf_n_len = get_len_buf(buf);
	if (!(new_buf = malloc(buf_len - buf_n_len + 1)))
		return (0);
	if (buf_n_len != buf_len)
	{
		while (buf[++buf_n_len])
			new_buf[counter++] = buf[buf_n_len];
	}
	new_buf[counter] = '\0';
	free(buf);
	return (new_buf);
}

int			checker_and_init(int fd, char **line, char *buf, int b_size)
{
	if (fd < 0 || !line || b_size < 1)
	{
		if (buf)
			free(buf);
		return (0);
	}
	if (!(*line = malloc(1)))
	{
		if (buf)
			free(buf);
		return (0);
	}
	line[0][0] = 0;
	return (1);
}
