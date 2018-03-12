# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daleksan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:23:14 by daleksan          #+#    #+#              #
#    Updated: 2017/10/29 14:53:29 by daleksan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc 

NAME = lem-in

SRC = lem_in.c check_line.c find_the_way.c checks.c checks_2.c check_3.c\
		line_parse.c find_way_2.c ants_moove.c get_next_line.c\
		check_line_add.c save_and_print_map.c free_everything.c

LIB = libft.a
LIBPRINT = libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	$(CC) -o $(NAME) $(OBJ) libft/libft.a ft_printf/libftprintf.a
	@echo "\033[32;1m<<lem-in done>>\033[0m"

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@rm -f $(OBJ)
	@echo "\033[31m<<Deleted objects>>\033[31m"
	
fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME)
	@echo "\033[31m<<Deleted lem-in>>\033[31m"

re: fclean all
