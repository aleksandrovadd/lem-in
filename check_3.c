/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:24:12 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 23:53:01 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			start_end_availability(t_rooms *rooms)
{
	int		i;
	t_rooms	*temp;

	i = 0;
	temp = rooms;
	while (temp)
	{
		if (temp->status == 1 || temp->status == -1)
			i++;
		temp = temp->next_room;
	}
	if (i != 2)
		error();
	return (0);
}

int			pipes_availability(t_rooms *rooms)
{
	t_rooms	*temp;
	int		i;

	i = 0;
	temp = rooms;
	while (temp)
	{
		if (temp->link)
			i++;
		temp = temp->next_room;
	}
	if (i == 0)
		error();
	return (0);
}

int			rooms_availability(t_rooms *rooms)
{
	if (rooms->name == NULL)
		error();
	return (1);
}

int			is_name(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

void		error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}
