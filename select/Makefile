#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjacque <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/25 16:33:32 by hjacque           #+#    #+#              #
#    Updated: 2016/01/29 17:16:00 by hjacque          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC =	gcc

NAME =  ft_select

SRC  =  ./abort_exit.c \
	./signal.c \
	./get_longest_word.c \
	./printarg.c \
	./loop_it.c \
	./screen.c \
	./term.c \
	./main.c \
	./tout.c \

OBJ =	$(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -Werror
LDFLAGS	+= -Llibft -lft -ltermcap

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
