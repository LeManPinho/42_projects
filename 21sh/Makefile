CC =	gcc

NAME =  ft_select

SRC  =  ./abort_exit.c \
	./signal.c \
	./loop_it.c \
	./term.c \
	./main.c \
	./all.c \
	./lst.c \

OBJ =	$(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -Werror
LDFLAGS	+= -Llibft -lft -ltermcap

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
