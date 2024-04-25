/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:33:44 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/25 16:16:48 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>
void *oui(void *args)
{
	(void)args;
	ft_printf("non\n\n");
	return (NULL);
}
int parsing (int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc > 6 || argc < 4)
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
	{
		data->arg.max_eating = ft_atoi(argv[5]);
	}
}

void	create_philo(t_data *data)
{
	int i;
	
	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->arg.philo_counter);
	while (i != data->arg.philo_counter)
	{
		data->philo[i].id = i;
		pthread_mutex_init(&data->philo[i].own_fork, NULL);
		if (i < 0)
			data->philo[i].left_fork = &data->philo[i - 1].own_fork;
		pthread_create(&data->philo[i].philo, NULL, routine, data);
		ft_printf("philo %d\n", i);
		i++;
	}
	data->philo[i].left_fork = &data->philo[0].own_fork;
}
int main(int argc, char **argv)
{
	//philo == thread
	//fork == mutex
	t_data data;
	if (parsing(argc, argv) == 1)
		return (ft_printf("Error: wrong input\n"), 1);
	converting_input(argv, &data);
	printf("%ld\n", actual_time() - data.arg.start_time);
	sleep(2);
	printf("%ld\n", actual_time() - data.arg.start_time);
	create_philo(&data);
	printf("%ld\n", actual_time() - data.arg.start_time);
	// pthread_create(&ouii, NULL, oui, NULL);
	// pthread_join(ouii, NULL);
	return (0);
}