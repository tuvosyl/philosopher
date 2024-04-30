/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:00:35 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/30 17:08:07 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
			pthread_mutex_lock(&data->time_eat);
			if ((actual_time() - data->philo[i].last_meal_timer)
				> data->arg.time_to_die)
			{
				pthread_mutex_unlock(&data->time_eat);
				pthread_mutex_lock(&data->dead);
				data->dead_flag = true;
				pthread_mutex_unlock(&data->dead);
				custom_printf(&data->philo[i], "dead", B_RED);
				return (NULL);
			}
			pthread_mutex_unlock(&data->time_eat);
			i++;
		}
	}
}
