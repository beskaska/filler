# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 15:19:28 by aimelda           #+#    #+#              #
#    Updated: 2020/03/14 20:53:11 by aimelda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	aimelda.filler

HDR		=	filler.h

SRC		=	filler.c		\
			parsing.c		\

OBJ		=	$(addsuffix .o, $(basename $(SRC)))

NEW_OBJ	=	$(addsuffix .o, $(basename $?)

C_FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	gcc $(C_FLAGS) -o $@ $(SRC) -L libft/ -lft

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all