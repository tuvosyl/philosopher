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
#include <sys/time.h>
typedef struct s_arg
{
	int philo_counter;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int max_eating;
	long int start_time;
}	t_arg;

typedef struct s_philo
{
	int id;
	pthread_t 	philo;
	pthread_mutex_t 	own_fork;
	pthread_mutex_t 	*left_fork;
	int			eating_count;
	int			dead;
}	t_philo;

typedef struct s_data
{
	t_arg arg;
	t_philo *philo;
}	t_data;

void			*routine(void *args);
long int		actual_time(void);
void	ft_usleep(long int time);

# endif