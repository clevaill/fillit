# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clevaill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 16:45:20 by clevaill          #+#    #+#              #
#    Updated: 2017/10/03 10:53:53 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS += -Wall -Wextra -Werror

SRC = main.c ft_check.c complete_map.c solve.c tetriminos.c

OBJ = $(SRC:.c=.o)

LIBFT = Libft/libft.a

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

$(LIBFT):
	@make -C Libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
		@rm -rf $(OBJ)
		@make -C libft clean

fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean

re: fclean all
