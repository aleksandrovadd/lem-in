/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and_print_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:19:01 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/28 23:50:22 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				fill_ids(t_farm *farm, t_rooms *path)
{
	int				i;
	t_rooms			*end_room;

	i = 1;
	end_room = find_end_room(farm, path, -1);
	while (writing_values(path, i) && end_room_links_empty(end_room))
		i++;
}

char				*save_line(t_farm *farm, char *line)
{
	unsigned int	i;
	char			*str;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = farm->map;
	str2 = line;
	if (str1 && str2)
	{
		if (!(str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 2)))
			return (NULL);
		while (*str1 || *str2)
		{
			if (*str1)
				str[i] = *str1++;
			else if (*str2)
				str[i] = *str2++;
			i++;
		}
		str[i++] = '\n';
		str[i] = '\0';
		free(farm->map);
	}
	return (i ? str : 0);
}

int					print_map(t_farm *farm)
{
	ft_printf("\033[1;31m%s\n\033[0m", farm->map);
	return (1);
}
