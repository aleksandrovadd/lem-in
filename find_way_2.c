/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:46:51 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/29 15:42:22 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				if_way(t_way *way)
{
	t_way		*temp;
	int			i;

	i = 0;
	temp = way;
	while (temp)
	{
		if (temp->name->status == 1 || temp->name->status == -1)
			i++;
		temp = temp->next_moove;
	}
	if (i != 2)
		return (0);
	return (1);
}

t_way			*way_init(t_rooms *path)
{
	t_way		*way;

	way = (t_way *)malloc(sizeof(t_way));
	ft_bzero(way, sizeof(t_way));
	way->final = -1;
	way->name = path;
	way->next_moove = NULL;
	return (way);
}

int				fill_id_room(t_rooms *room, int value)
{
	int			i;
	t_connect	*links;

	i = 0;
	links = room->link;
	while (links)
	{
		if (links->connect->id == 0)
		{
			links->connect->id = value;
			i++;
		}
		links = links->next_con;
	}
	return (i);
}

int				writing_values(t_rooms *all_rooms, int value)
{
	t_rooms		*copy_rooms;
	int			i;

	i = 0;
	copy_rooms = all_rooms;
	while (copy_rooms)
	{
		if (copy_rooms->id == value)
			i += fill_id_room(copy_rooms, value + 1);
		copy_rooms = copy_rooms->next_room;
	}
	return (i);
}

int				end_room_links_empty(t_rooms *end_room)
{
	int			i;
	t_connect	*links;

	i = 0;
	links = end_room->link;
	while (links)
	{
		if (links->connect->id == 0)
			i++;
		links = links->next_con;
	}
	return (i);
}
