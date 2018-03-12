/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_moove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:32:34 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/26 17:32:41 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			start_end_access(t_rooms *rooms)
{
	t_rooms	*temp;
	int		i;

	temp = rooms;
	while (temp)
	{
		if (temp->status == 1 || temp->status == -1)
		{
			if (temp->link != NULL)
				i++;
		}
		temp = temp->next_room;
	}
	if (i != 2)
		error();
	return (0);
}

void		first_room(t_farm *farm, t_way *current, t_way *next)
{
	current->name->status = farm->ant;
	ft_printf("\033[1;34mL%d-%s \033[0m", current->name->status,
	current->name->name);
	farm->ant++;
	if (farm->rout_length == 2)
		farm->end_num++;
}

void		ants_moove(t_farm *farm, t_way *current, t_way *next)
{
	if (next->name->id == 1)
	{
		if (farm->ant <= farm->num)
			first_room(farm, current, next);
		return ;
	}
	if (current->name->id != -1 && next->name->status != 0 &&
		current->name->status == 0)
	{
		current->name->status = next->name->status;
		next->name->status = 0;
		ft_printf("L%d-%s ", current->name->status, current->name->name);
	}
	if (current->name->id == -1 && next->name->status != 0)
	{
		farm->end_num = next->name->status;
		ft_printf("\033[1;33mL%d-%s \033[0m", next->name->status,
		current->name->name);
		next->name->status = 0;
	}
	ants_moove(farm, next, next->next_moove);
}

void		run_ants(t_farm *farm)
{
	while (farm->end_num < farm->num)
	{
		ants_moove(farm, farm->rout, farm->rout->next_moove);
		ft_printf("\n");
	}
}
