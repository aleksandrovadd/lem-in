/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:21:09 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 22:24:00 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			work_with_rooms(t_farm *farm, char *line, t_rooms *rooms)
{
	t_rooms		*new;

	new = (t_rooms *)malloc(sizeof(t_rooms));
	ft_bzero(new, sizeof(t_rooms));
	if (check_rooms(line))
	{
		if (check_structure(rooms, line))
		{
			parse_rooms(new, line, 0);
			rooms_add(rooms, new);
			if (new->name == NULL)
				free(new);
		}
	}
}

void			free_line(char *line)
{
	free(line);
	line = NULL;
}

void			save_and_free(t_farm *farm, char *line)
{
	farm->map = save_line(farm, line);
	free(line);
	line = NULL;
}

void			double_connection_check(t_rooms *tmp, char *name,
				t_connect *link)
{
	t_connect	*temp_c;

	temp_c = tmp->link;
	while (temp_c->next_con)
	{
		if (ft_strcmp(temp_c->connect->name, name) == 0)
		{
			free_exit(link);
			return ;
		}
		temp_c = temp_c->next_con;
	}
	temp_c->next_con = link;
}

void			double_connection_check_1(t_rooms *rooms,
				char **name, t_connect *link)
{
	t_connect	*temp_c;

	temp_c = rooms->link;
	while (temp_c->next_con)
	{
		if (ft_strcmp(temp_c->connect->name, name[1]) == 0)
		{
			free_exit(link);
			return ;
		}
		temp_c = temp_c->next_con;
	}
	temp_c->next_con = link;
}
