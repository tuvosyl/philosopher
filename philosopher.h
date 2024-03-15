#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <pthread.h>

typedef struct s_arg
{
	size_t philo_counter;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t max_eating;
}	t_arg;

typedef struct s_philo
{
	pthread_t 	own_fork;
	pthread_t 	left_fork;
	int			eating_count;
	int			dead;
}	t_philo;

typedef struct s_data
{
	t_arg arg;
	t_philo *philo;
}	t_data;

# endif