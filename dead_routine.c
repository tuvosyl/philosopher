/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:00:35 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/01 17:34:24 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	dead_routine2(t_data *data, int i)
{
	pthread_mutex_unlock(&data->time_eat);
	pthread_mutex_lock(&data->dead);
	data->dead_flag = true;
	pthread_mutex_unlock(&data->dead);
	custom_printf(&data->philo[i], "dead", B_RED);
}

void	*dead_routine(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	ft_usleep(10);
	while (12)
	{
		i = 0;
		while (i < data->arg.philo_counter)
		{
			if (check_death(data))
				return (NULL);
			pthread_mutex_lock(&data->time_eat);
			if ((actual_time() - data->philo[i].last_meal_timer)
				> data->arg.time_to_die)
				return (dead_routine2(data, i), NULL);
			pthread_mutex_unlock(&data->time_eat);
			i++;
		}
	}
}
