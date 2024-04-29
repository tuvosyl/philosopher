NAME 		= philo

CC 			= cc
RM			= rm -f

CFLAGS 		+= -g -Wall -Wextra -Werror -O3
THREAD_FLAG		+= -pthread

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= main.c routine.c utils.c dead_routine.c aile_ou_cuisse.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(THREAD_FLAG)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if [ -d "$(FT)" ]; then $(MAKE) clean -C $(FT); fi
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re

