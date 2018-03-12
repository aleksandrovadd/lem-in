/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:17:03 by dverbyts          #+#    #+#             */
/*   Updated: 2017/10/13 14:17:05 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_find_way(t_lem *j)
{
	t_room	*room_buf;
	t_way	*w;

	room_buf = j->room;
	while (room_buf->start != 1)
		room_buf = room_buf->next_room;
	if (room_buf->start == 1)
	{
		w = lem_in_way_init(room_buf, 0);
		room_buf->vertex = 0;
		lem_in_recursion(j, room_buf, 0, w);
	}
	else
		j->error = 1;
	if (j->way == NULL)
		j->error = 1;
}

void	lem_in_recursion(t_lem *j, t_room *room, int vertex, t_way *way)
{
	t_link	*b;
	t_way	*w;

	w = way;
	b = room->link;
	while (b != NULL)
	{
		if (b->link_room->vertex > (vertex + 1) || b->link_room->vertex == -1)
			b->link_room->vertex = vertex + 1;
		if (b->link_room->vertex == (vertex + 1))
		{
			if (lem_in_save_way(j, b->link_room, w) == 0)
				lem_in_recursion(j, b->link_room, vertex + 1, w);
			lem_in_del_steps(w, vertex + 1);
		}
		b = b->next_link;
	}
}

void	lem_in_del_steps(t_way *w1, int vertex)
{
	t_way	*w2;

	while (w1->vertex != vertex)
	{
		w2 = w1;
		w1 = w1->next_step;
	}
	while (w1 != NULL)
	{
		w1->vertex = 0;
		w1->room = NULL;
		w1->next_step = NULL;
		free(w1);
		w1 = NULL;
		w2->next_step = NULL;
	}
}

int		lem_in_save_way(t_lem *j, t_room *room, t_way *way)
{
	t_way	*w;

	w = way;
	while (w->next_step != NULL)
		w = w->next_step;
	w->next_step = (t_way *)malloc(sizeof(t_way));
	w->next_step->vertex = room->vertex;
	w->next_step->room = room;
	w->next_step->next_step = NULL;
	if (room->end == 1)
	{
		j->way = lem_in_we_have_way(j, way, -1);
		return (1);
	}
	return (0);
}

t_way	**lem_in_we_have_way(t_lem *j, t_way *way, int e)
{
	t_way	**ww;
	t_way	*w1;
	t_way	*w2;

	j->way_number += 1;
	ww = (t_way **)malloc(sizeof(t_way *) * (j->way_number + 1));
	ft_bzero(ww, sizeof(t_way *) * (j->way_number + 1));
	while (++e < j->way_number)
		ww[e] = j->way[e];
	w1 = lem_in_way_init(way->room, way->vertex);
	ww[j->way_number] = w1;
	w2 = way->next_step;
	while (w2 != NULL)
	{
		w1->next_step = lem_in_way_init(w2->room, w2->vertex);
		w1 = w1->next_step;
		w2 = w2->next_step;
	}
	if (j->way != NULL)
		free(j->way);
	return (ww);
}
