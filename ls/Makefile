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

NAME =  ft_ls

SRC  =  ./ft_ls.c \
		./clearlst.c \
		./addelem.c \
		./sortlist.c \
		./print.c \
		./recursive.c \
		./tools.c \
		./info.c \
		./functions.c \
		./functionspls.c \

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
