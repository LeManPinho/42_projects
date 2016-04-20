CC =	gcc

NAME =  minishell

SRC  =  ./main.c \
		    ./dlst.c \
		    ./get_next_line.c \
		    ./setenv.c \
		    ./cd.c \
		    ./fork.c \

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
