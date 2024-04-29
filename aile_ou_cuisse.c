/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aile_ou_cuisse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:44:31 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/29 18:18:37 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*all_eat_routine(void *args)
{
	t_data *data;
	int i;
	bool state;
	
	data = (t_data *)args;
	i = 0;
	while(12)
	{
		i = 0;
		state = true;
		while(i != data->arg.philo_counter)
		{
			pthread_mutex_lock(&data->time_eat);
			if (!(data->philo[i].eating_count >= data->arg.max_eating))
			{
				state = false;
				pthread_mutex_unlock(&data->time_eat);
				break;
			}
			pthread_mutex_unlock(&data->time_eat);
			i++;
		}
		if (state == true)
		{
			pthread_mutex_lock(&data->dead);
			data->dead_flag = true;
			pthread_mutex_unlock(&data->dead);
			return (NULL);
		}
	}
}