/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:24:34 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 22:39:48 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_structure(t_rooms *rooms, char *line)
{
	t_rooms *temp;
	int		x;
	int		y;
	char	**a;
	int		flag;

	flag = 0;
	a = ft_strsplit(line, ' ');
	x = ft_atoi(a[1]);
	y = ft_atoi(a[2]);
	free_split(a);
	a = ft_strsplit(line, ' ');
	temp = rooms;
	while (temp)
	{
		if (temp->name != NULL && ft_strcmp(temp->name, a[0]) == 0)
			error();
		else if (temp->coord_x == x && temp->coord_y == y)
			error();
		temp = temp->next_room;
	}
	free_split(a);
	return (1);
}

int			check_name(char *name)
{
	int		i;

	i = 0;
	while (name[i] != ' ')
	{
		if (name[0] == 'L' || (!(is_name(name[i]))))
			error();
		i++;
	}
	return (1);
}

int			check_coord(char **coord)
{
	int		i;
	int		a;
	int		len;

	a = 1;
	while (a < 3)
	{
		i = 0;
		len = (int)ft_strlen(coord[a]);
		while (len > 0)
		{
			if (coord[a][0] == '-')
				i++;
			if (ft_isdigit(coord[a][i]))
				i++;
			else
				error();
			len--;
		}
		a++;
	}
	free_split(coord);
	return (1);
}

int			check_rooms(char *line)
{
	int		i;
	char	**coord;

	i = 0;
	while (line[i] != ' ')
		i++;
	coord = ft_strsplit(line, ' ');
	if (check_name(line) && check_coord(coord))
		return (1);
	else
		error();
	return (0);
}
