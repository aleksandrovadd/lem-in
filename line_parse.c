/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:03:41 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 23:09:28 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*find_start(t_rooms *rooms, t_rooms *path)
{
	t_rooms	*find;

	find = rooms;
	while (find)
	{
		if (find->status == 1)
		{
			path = find;
			path->id = 1;
			return (path);
		}
		find = find->next_room;
	}
	return (NULL);
}

t_rooms		*find_end_room(t_farm *farm, t_rooms *rooms, int id)
{
	t_rooms	*find;
	t_rooms	*end_room;

	find = rooms;
	while (find)
	{
		if (find->status == -1)
		{
			end_room = find;
			end_room->id = -1;
			farm->end = find;
			return (end_room);
		}
		find = find->next_room;
	}
	return (NULL);
}

t_rooms		*rooms_add(t_rooms *rooms, t_rooms *new)
{
	t_rooms	*temp;

	temp = rooms;
	while (temp->next_room)
		temp = temp->next_room;
	temp->next_room = new;
	return (rooms);
}

t_rooms		*find_name_2(t_rooms *rooms, char *name_2)
{
	t_rooms	*temp;

	temp = rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, name_2) == 0)
			return (temp);
		temp = temp->next_room;
	}
	return (NULL);
}

t_rooms		*parse_rooms(t_rooms *rooms, char *str, int status)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	rooms->name = (char *)malloc(sizeof(char) * (i + 1));
	ft_bzero(rooms->name, i + 1);
	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
	{
		rooms->name[i] = str[i];
		i++;
	}
	str = ft_strchr(str, ' ');
	rooms->coord_x = ft_atoi(str);
	str++;
	str = ft_strchr(str, ' ');
	rooms->coord_y = ft_atoi(str);
	rooms->status = status;
	return (rooms);
}
