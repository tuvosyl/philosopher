/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:33:44 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/30 16:46:05 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>
void wait_all_philo(t_data *data)
{
	int i;

	i = 0;
	pthread_create(&data->tcheck_dead, NULL, dead_routine, data);
	pthread_create(&data->tall_eat, NULL, all_eat_routine, data);
	while(i != data->arg.philo_counter)
	{
		pthread_join(data->philo[i].philo, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->eating_count);
	pthread_mutex_destroy(&data->time_eat);
	pthread_mutex_destroy(&data->write);
	// pthread_join(data->tall_eat, NULL);
	// pthread_join(data->tcheck_dead, NULL);
}

int parsing (int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc > 6 || argc <= 4)
		return (1);
	while(argv[i] && i != 5)
	{
		while(argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void converting_input(char **argv, t_data *data)
{
	data->arg.philo_counter = ft_atoi(argv[1]);
	data->arg.time_to_die = ft_atoi(argv[2]);
	data->arg.time_to_eat = ft_atoi(argv[3]);
	data->arg.time_to_sleep = ft_atoi(argv[4]);
	data->arg.start_time = actual_time();
	if (argv[5])
		data->arg.max_eating = ft_atoi(argv[5]);
	else
		data->arg.max_eating = -1;
}

void	create_philo(t_data *data)
{
	int i;
	
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->arg.philo_counter);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->arg.philo_counter);
	data->dead_flag = false;
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->eating_count, NULL);
	pthread_mutex_init(&data->time_eat, NULL);
	pthread_mutex_init(&data->write, NULL);
	while (i != data->arg.philo_counter)
	{
		data->philo[i].id = i;
		data->wait_timer = 0;
		data->philo[i].eating_count = 0;
		data->philo[i].last_meal_timer = 0;
		data->philo[i].data = data;
		pthread_mutex_init(&data->fork[i], NULL);
		data->philo[i].own_fork = &data->fork[i];
		if (i >= 1)
			data->philo[i].left_fork = &data->fork[i - 1];
		i++;
	}
	i--;
	data->philo[0].left_fork = &data->fork[i];
	i = 0;
	while(i != data->arg.philo_counter)
	{
		pthread_create(&data->philo[i].philo, NULL, routine, &data->philo[i]);
		i++;
	}
}
int main(int argc, char **argv)
{
	//philo == thread
	//fork == mutex
	t_data data;

	if (parsing(argc, argv) == 1)
		return (printf("Error: wrong input\n"), 1);
	converting_input(argv, &data);
	if (data.arg.philo_counter == 1)
	{
		printf("%s%d %d %s%s\n",B_RED, 0, 1, "died", RESET);
		return (0);
	}
	create_philo(&data);
	wait_all_philo(&data);
	return (0);
}
