NAME 		= philo

CC 			= cc
RM			= rm -f

CFLAGS 		+= -g -Wall -Wextra -Werror -O3 -fsanitize=thread
THREAD_FLAG		+= 

SRC 		= main.c routine.c utils.c utils2.c dead_routine.c aile_ou_cuisse.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(THREAD_FLAG)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re

