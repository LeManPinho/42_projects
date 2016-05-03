# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho <apinho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 14:17:58 by apinho            #+#    #+#              #
#    Updated: 2016/05/03 15:02:00 by apinho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

NAME =  minishell

SRC  =  ./main.c \
		    ./dlst.c \
		    ./get_next_line.c \
		    ./setenv.c \
		    ./cd.c \
		    ./fork.c \
		    ./isallspace.c \
		    ./lst_to_tab.c \
		    ./env_i.c \
		    ./fork_i.c \

OBJ =	$(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -Werror -g
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
