/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentins <valentins@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:38:19 by valentins         #+#    #+#             */
/*   Updated: 2024/04/25 17:32:53 by valentins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	think(t_data *data)
{
	pthread_mutex_lock(&data->write);
	ft_printf("%ld %d is thinking\n", actual_time() - data->arg.start_time, data->philo->id);
	pthread_mutex_unlock(&data->write);
}
void *routine(void *args)
{
	t_data *data;

	data = (t_data *)args;
	while(12)
	{
		//eat
		//sleep
		//think
		think(data);
	}
	return (NULL);
}

