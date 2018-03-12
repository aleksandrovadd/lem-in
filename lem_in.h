/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:53:29 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/29 19:38:05 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "ft_printf/src/ft_printf.h"

typedef struct			s_farm
{
	int					num;
	int					ant;
	int					end_num;
	int					rout_length;
	char				*map;
	struct s_rooms		*start;
	struct s_rooms		*end;
	struct s_way		*rout;
}						t_farm;

typedef struct			s_connect
{
	struct s_rooms		*connect;
	struct s_connect	*next_con;
}						t_connect;

typedef struct			s_rooms
{
	int					id;
	char				*name;
	int					coord_x;
	int					visited;
	int					coord_y;
	int					status;
	struct s_connect	*link;
	struct s_rooms		*next_room;
}						t_rooms;

typedef struct			s_way
{
	int					final;
	struct s_rooms		*name;
	struct s_way		*next_moove;
}						t_way;

void					ants_num(t_farm *farm);
void					start_end(t_farm *farm, t_rooms *rooms);
void					end_parse(t_farm *farm, t_rooms *rooms, t_rooms *new);
void					check_line(t_farm *farm, char *line, t_rooms *rooms);
void					work_with_rooms(t_farm *farm, char *line,
						t_rooms *rooms);
void					free_line(char *line);
void					save_and_free(t_farm *farm, char *line);
void					double_connection_check(t_rooms *tmp,
						char *name, t_connect *link);
void					double_connection_check_1(t_rooms *rooms,
						char **name, t_connect *link);
int						check_rooms(char *str);
int						check_structure(t_rooms *rooms, char *line);
int						check_name(char *name);
int						check_coord(char **coord);
int						start_end_availability(t_rooms *rooms);
int						start_end_access(t_rooms *rooms);
int						pipes_availability(t_rooms *rooms);
int						rooms_availability(t_rooms *rooms);
int						commands(t_farm *farm, t_rooms *rooms,
						t_rooms *new, char *line);
int						is_room(char *line);
int						is_name(char c);
int						is_comment(char *line);
int						is_command(char *line);
int						is_connection(t_rooms *rooms, char *line);
int						save_way(t_farm *farm, t_rooms *path, t_way *way);
int						writing_values(t_rooms *all_rooms, int value);
int						end_room_links_empty(t_rooms *end_room);
int						fill_id_room(t_rooms *room, int value);
void					fill_ids(t_farm *farm, t_rooms *path);
int						rout_length(t_farm *farm);
int						if_way(t_way *way);
void					find_way(t_farm *farm, t_rooms *rooms);
void					parse_connections(t_rooms *rooms, char *line);
int						recursion(t_farm *farm, t_way *way,
						t_rooms *path, int id);
void					error(void);
int						print_map(t_farm *farm);
void					ants_moove(t_farm *farm, t_way *current, t_way *next);
char					*save_line(t_farm *farm, char *line);
t_rooms					*find_end_room(t_farm *farm, t_rooms *rooms, int id);
t_rooms					*find_start(t_rooms *rooms, t_rooms *path);
t_rooms					*rooms_add(t_rooms *rooms, t_rooms *new);
t_rooms					*find_name_2(t_rooms *rooms, char *name_2);
t_rooms					*parse_rooms(t_rooms *rooms, char *str, int status);
t_way					*way_init(t_rooms *path);
void					free_rooms_exit(t_rooms *rooms);
void					free_exit(t_connect *link);
void					free_exit_farm(t_farm *farm);
void					free_split(char **str);
void					free_way(t_way *way);
void					run_ants(t_farm *farm);

#endif
