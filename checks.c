/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:25:24 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 21:42:35 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			double_connection(t_rooms *rooms, char **name)
{
	int		i;
	t_rooms	*temp;

	i = 0;
	temp = rooms;
	while (temp)
	{
		if ((ft_strcmp(name[0], temp->name) == 0) ||
			(ft_strcmp(name[1], temp->name) == 0))
			i++;
		temp = temp->next_room;
	}
	if (i != 2)
		error();
	return (1);
}

int			is_connection(t_rooms *rooms, char *line)
{
	int		i;
	int		a;
	char	**name;

	i = 0;
	a = 0;
	name = ft_strsplit(line, '-');
	a = ft_strlen(line);
	if (name[1] == NULL || a > (ft_strlen(name[0]) + ft_strlen(name[1]) + 1))
		error();
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || (line[ft_strlen(name[0])] != '-'))
			error();
		i++;
	}
	double_connection(rooms, name);
	free_split(name);
	return (1);
}

int			is_comment(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '#' && line[i + 1] != '#')
		return (1);
	else if (line[i] == '#' && line[i + 1] == '#' && !(is_command(line)))
		return (1);
	return (0);
}

int			is_command(char *line)
{
	if ((ft_strcmp(line, "##start") == 0) ||
		(ft_strcmp(line, "##end") == 0))
		return (1);
	return (0);
}

int			is_room(char *line)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			a++;
		i++;
	}
	if (a == 2)
		return (1);
	return (0);
}
