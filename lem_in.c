/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:52:19 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/29 15:43:48 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ants_num(t_farm *farm)
{
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(0, &str) && (is_comment(str)))
		save_and_free(farm, str);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			error();
	}
	farm->num = ft_atoi(str);
	save_and_free(farm, str);
	if (farm->num <= 0)
		error();
}

void		parse_all_structures(t_farm *farm, t_rooms *rooms)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if ((ft_strequ(line, "\0")) || (ft_strequ(line, "\n")))
			error();
		farm->map = save_line(farm, line);
		if (!(ft_strcmp(line, "##break")))
		{
			free(line);
			line = NULL;
			break ;
		}
		check_line(farm, line, rooms);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void		start_end(t_farm *farm, t_rooms *rooms)
{
	farm->start = rooms;
	farm->ant = 1;
	farm->start->next_room = NULL;
	farm->end_num = 0;
	farm->map = (char *)malloc(sizeof(char));
	rooms->coord_x = -1;
	rooms->coord_y = -1;
}

int			check_struct_rooms(t_rooms *rooms)
{
	start_end_availability(rooms);
	start_end_access(rooms);
	pipes_availability(rooms);
	return (0);
}

int			main(void)
{
	t_farm	*farm;
	t_rooms	*rooms;

	farm = (t_farm *)malloc(sizeof(t_farm));
	rooms = (t_rooms *)malloc(sizeof(t_rooms));
	ft_bzero(farm, sizeof(t_farm));
	ft_bzero(rooms, sizeof(t_rooms));
	start_end(farm, rooms);
	ants_num(farm);
	parse_all_structures(farm, rooms);
	check_struct_rooms(rooms);
	find_way(farm, rooms);
	print_map(farm);
	ft_printf("\n");
	run_ants(farm);
	free_rooms_exit(rooms);
	free_exit_farm(farm);
	return (0);
}
