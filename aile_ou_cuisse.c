/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aile_ou_cuisse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:44:31 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/30 15:40:05 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*all_eat_routine(void *args)
{
	t_data *data;
	int i;
	
	data = (t_data *)args;
	if (data->arg.max_eating == -1)
		return (NULL);
	ft_usleep(10);
	while(1)
	{
		i = 0;
		while(i < data->arg.philo_counter)
		{
			pthread_mutex_lock(&data->eating_count);
			if (data->arg.max_eating >= data->philo[i].eating_count)
			{
				pthread_mutex_unlock(&data->eating_count);
				// custom_printf(&data->philo[1], "oui", B_RED);
				break ;
			}
			pthread_mutex_unlock(&data->eating_count);
			i++;
		}
		if(i >= data->arg.philo_counter)
		{
			pthread_mutex_lock(&data->dead);
			data->dead_flag = true;
			pthread_mutex_unlock(&data->dead);
			return (NULL);
		}
	}
	custom_printf(&data->philo[1], "non", B_RED);
}