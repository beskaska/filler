# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimelda <aimelda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 15:19:28 by aimelda           #+#    #+#              #
#    Updated: 2020/06/06 22:47:10 by aimelda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	aimelda.filler

HDR		=	filler.h

SRC		=	main.c			\
			filler.c		\
			parsing.c		\
			defining.c		\
			freeing.c		\

LIBS	=	libft.a
LIBDIR	=	libft/
LIBPATH	=	$(addsuffix $(LIBS), $(LIBDIR))

CFLAGS	=	-Wall -Wextra -Werror

all: makelibs $(NAME)

$(NAME): $(SRC) $(HDR) $(LIBPATH)
	gcc $(CFLAGS) -o $@ $(SRC) -L $(LIBDIR) -lft

makelibs:
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBPATH)

re: fclean all

.PHONY: all clean fclean re makelibs