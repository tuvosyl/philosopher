/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:02:02 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/08 01:51:10 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define RESET "\033[0m"
# define B_RED "\033[1;31m"
# define B_GREEN "\033[1;32m"
# define B_YELLOW "\033[1;33m"
# define B_CYAN "\033[1;36m"
# define B_WHITE "\033[1;37m"

typedef struct s_arg
{
	int			philo_counter;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			max_eating;
	long int	start_time;
}	t_arg;

typedef struct s_philo
{
	struct s_data		*data;
	int					id;
	pthread_t			philo;
	pthread_mutex_t		*own_fork;
	pthread_mutex_t		*left_fork;
	int					eating_count;
	long int			last_meal_timer;
}	t_philo;

typedef struct s_data
{
	t_arg			arg;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_t		tcheck_dead;
	pthread_t		tall_eat;
	bool			dead_flag;
	int				wait_timer;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}	t_data;

void			*routine(void *args);
int				check_death(t_data *data);
void			custom_printf(t_philo *philo, char *str, char *color);
long int		actual_time(void);
void			ft_usleep(long int time);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
int				ft_strncmp(const char *s1, const char *s2, size_t n );
void			*dead_routine(void *args);
void			*all_eat_routine(void *args);
void			norme(t_data *data);

#endif