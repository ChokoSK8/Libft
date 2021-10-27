/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:58:31 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:44:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			get_param_cub(t_param *param, int fd)
{
	char	*line;

	if (fd < 0)
	{
		ft_putstr_fd("Le fichier n'a pas pu être ouvert !\n", 2);
		return (0);
	}
	if (!(param->tab = malloc(10000)))
	{
		ft_putstr_fd("Un malloc a échoué !\n", 2);
		return (0);
	}
	line = NULL;
	line = fill_elements(param, fd, line);
	if (!check_all(param->checks, param))
	{
		free(line);
		return (0);
	}
	if (!fill_tab_map(line, fd, param->tab, param))
		return (0);
	return (1);
}

char		*fill_elements(t_param *param, int fd, char *line)
{
	int		done;
	int		ret;

	done = 0;
	while (!done)
	{
		if (!(line = get_element(fd, param)))
			return (0);
		if (!(ret = fill_param(param, line)))
		{
			free_tab_checks(param);
			free(line);
			return (0);
		}
		param->checks[ret - 1] = 1;
		done = is_map(line);
		if (!done)
			free(line);
	}
	return (line);
}

char		*get_element(int fd, t_param *param)
{
	int			find;
	char		*line;

	find = 0;
	while (!find)
	{
		if (get_next_line(fd, &line, 1) == -1)
		{
			free_tab_checks(param);
			ft_putstr_fd("Erreur lecture ou pas de map!\n", 2);
			return (NULL);
		}
		if (*line)
			find = 1;
		else
			free(line);
	}
	return (line);
}

int			fill_param(t_param *param, char *line)
{
	if (ft_strnstr(line, "NO", 5))
		return (get_no_path(param, line));
	else if (ft_strnstr(line, "SO", 5))
		return (get_so_path(param, line));
	else if (ft_strnstr(line, "EA", 5))
		return (get_ea_path(param, line));
	else if (ft_strnstr(line, "WE", 5))
		return (get_we_path(param, line));
	else if (ft_strnchr(line, 'R', 3))
		return (get_resolution(param, line));
	else if (ft_strnchr(line, 'C', 3))
		return (get_color(line, param, 'C'));
	else if (ft_strnchr(line, 'F', 3))
		return (get_color(line, param, 'F'));
	else if (ft_strnchr(line, 'S', 3))
		return (get_sp_path(param, line));
	return (1);
}

int			is_map(char *line)
{
	while (*line)
	{
		if (ft_isalpha(*line))
			return (0);
		line++;
	}
	return (1);
}
