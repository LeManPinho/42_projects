# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho <apinho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 14:17:58 by apinho            #+#    #+#              #
#    Updated: 2016/10/06 17:34:59 by apinho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

NAME =  minishell

SRC  =  ./srcs/main.c \
		    ./srcs/dlst.c \
		    ./srcs/get_next_line.c \
		    ./srcs/setenv.c \
		    ./srcs/cd.c \
		    ./srcs/fork.c \
		    ./srcs/isallspace.c \
		    ./srcs/lst_to_tab.c \
		    ./srcs/env_i.c \
		    ./srcs/fork_i.c \
		    ./srcs/testecho.c \
		    ./srcs/other.c \

OBJ =	$(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -Werror -I includes
LDFLAGS	+= -Llibft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
