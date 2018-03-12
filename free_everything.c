/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:50:38 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 23:50:40 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_way(t_way *way)
{
	free_rooms_exit(way->name);
}

void	free_exit_farm(t_farm *farm)
{
	free(farm->map);
	while (farm->rout)
	{
		free(farm->rout);
		farm->rout = farm->rout->next_moove;
	}
}

void	free_exit(t_connect *link)
{
	while (link)
	{
		free(link);
		link = link->next_con;
	}
}

void	free_rooms_exit(t_rooms *rooms)
{
	while (rooms)
	{
		free(rooms->name);
		free_exit(rooms->link);
		rooms = rooms->next_room;
	}
}

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
