/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:43:55 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 22:20:22 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			end_parse(t_farm *farm, t_rooms *rooms, t_rooms *new)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line) && is_comment(line))
		save_and_free(farm, line);
	if (is_room(line) && (farm->map = save_line(farm, line)))
	{
		if (check_rooms(line))
		{
			parse_rooms(new, line, -1);
			rooms_add(rooms, new);
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	else
		error();
}

int				commands(t_farm *farm, t_rooms *rooms, t_rooms *new,
				char *line_in)
{
	char		*line;

	line = NULL;
	if (ft_strcmp("##start", line_in) == 0)
	{
		while (get_next_line(0, &line) && is_comment(line))
			save_and_free(farm, line);
		if (is_room(line) && (farm->map = save_line(farm, line)))
		{
			if (check_rooms(line) && !farm->start->name)
				parse_rooms(rooms, line, 1);
			if (line)
				free_line(line);
		}
		else
			error();
	}
	else if (ft_strcmp("##end", line_in) == 0)
		end_parse(farm, rooms, new);
	else
		error();
	return (1);
}

void			parse_second_connection(t_rooms *tmp, char *name, char *name_1)
{
	t_connect	*link;
	t_rooms		*structure;

	structure = tmp;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			link = (t_connect *)malloc(sizeof(t_connect));
			ft_bzero(link, sizeof(t_connect));
			link->connect = find_name_2(structure, name_1);
			if (!tmp->link)
				tmp->link = link;
			else
				double_connection_check(tmp, name, link);
			return ;
		}
		tmp = tmp->next_room;
	}
}

void			parse_connections(t_rooms *rooms, char *line)
{
	char		**name;
	t_connect	*link;
	t_rooms		*tmp;

	name = ft_strsplit(line, '-');
	tmp = rooms;
	while (rooms)
	{
		if (ft_strcmp(rooms->name, name[0]) == 0)
		{
			link = (t_connect *)malloc(sizeof(t_connect));
			ft_bzero(link, sizeof(t_connect));
			link->connect = find_name_2(tmp, name[1]);
			if (!rooms->link)
				rooms->link = link;
			else
				double_connection_check_1(rooms, name, link);
			parse_second_connection(tmp, name[1], name[0]);
			free_split(name);
			return ;
		}
		rooms = rooms->next_room;
	}
	free_split(name);
}

void			check_line(t_farm *farm, char *line, t_rooms *rooms)
{
	t_rooms		*new;

	if (is_comment(line) == 1)
		return ;
	else if (is_command(line) == 1)
	{
		new = (t_rooms *)malloc(sizeof(t_rooms));
		ft_bzero(new, sizeof(t_rooms));
		commands(farm, rooms, new, line);
		if (new->name == NULL)
			free(new);
	}
	else if (is_room(line))
		work_with_rooms(farm, line, rooms);
	else if ((rooms_availability(rooms)) && is_connection(rooms, line))
		parse_connections(rooms, line);
	else
		error();
}
