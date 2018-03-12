/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:40:41 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 22:46:24 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				find_min_value(t_connect *link)
{
	t_connect	*road;
	int			res;

	res = 2147483647;
	road = link;
	while (road != NULL)
	{
		if (road->connect->id < res && road->connect->visited == 0)
		{
			res = road->connect->id;
			road->connect->visited++;
		}
		else if (road->connect->status == 1)
			res = road->connect->id;
		road = road->next_con;
	}
	return (res);
}

int				rout_length(t_farm *farm)
{
	t_way		*temp;
	int			i;

	i = 0;
	temp = farm->rout;
	if (farm->rout->name)
	{
		while (temp)
		{
			i++;
			temp = temp->next_moove;
		}
	}
	else
		error();
	return (i);
}

void			find_way(t_farm *farm, t_rooms *rooms)
{
	t_rooms		*path;
	t_way		*w;

	path = find_start(rooms, path);
	if (path)
	{
		path->id = 1;
		fill_ids(farm, path);
		while (farm->end->link)
		{
			w = way_init(farm->end);
			recursion(farm, w, farm->end, find_min_value(farm->end->link));
			if (if_way(w) == 1)
				break ;
			free_way(w);
			farm->end->link = farm->end->link->next_con;
		}
	}
	if (!path || if_way(w) != 1)
	{
		free(path);
		error();
	}
	farm->rout = w;
	farm->rout_length = rout_length(farm);
}

int				recursion(t_farm *farm, t_way *way,
				t_rooms *current_room, int id)
{
	t_connect	*road;

	road = current_room->link;
	if (current_room->status == 1)
	{
		save_way(farm, current_room, way);
		return (1);
	}
	while (road != NULL)
	{
		if (road->connect->id == id)
		{
			if (current_room->status != -1)
				save_way(farm, current_room, way);
			if (recursion(farm, way, road->connect, id - 1))
				return (1);
		}
		road = road->next_con;
	}
	return (0);
}

int				save_way(t_farm *farm, t_rooms *path, t_way *way)
{
	t_way		*road;

	road = way;
	while (road->next_moove != NULL)
		road = road->next_moove;
	road->next_moove = (t_way *)malloc(sizeof(t_way));
	road->next_moove->name = path;
	road->next_moove->next_moove = NULL;
	return (0);
}
