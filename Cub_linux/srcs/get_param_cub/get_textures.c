/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:56:59 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 18:13:21 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			get_so_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("SO", line))
		return (0);
	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->so = ft_strdup(path)))
	{
		free(path);
		ft_putstr_fd("Un malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (2);
}

int			get_ea_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("EA", line))
		return (0);
	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->ea = ft_strdup(path)))
	{
		free(path);
		ft_putstr_fd("Un malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (3);
}

int			get_we_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("WE", line))
		return (0);
	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->we = ft_strdup(path)))
	{
		free(path);
		ft_putstr_fd("Un malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (4);
}

int			get_sp_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("S", line))
		return (0);
	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->sp = ft_strdup(path)))
	{
		free(path);
		ft_putstr_fd("Un malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (8);
}

int			get_no_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("NO", line))
		return (0);
	if (!(path = malloc(ft_strlen(line))))
		return (0);
	c = 0;
	while (line[c] && line[c] != '/')
		c++;
	counter = 0;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	if (!(param->no = ft_strdup(path)))
	{
		free(path);
		ft_putstr_fd("Un malloc a échoué !\n", 2);
		return (0);
	}
	free(path);
	return (1);
}
