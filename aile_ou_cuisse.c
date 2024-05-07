/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aile_ou_cuisse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:44:31 by vsoltys           #+#    #+#             */
/*   Updated: 2024/05/08 01:58:23 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	condition(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	data->dead_flag = true;
	pthread_mutex_unlock(&data->dead);
}

void	*all_eat_routine(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	if (data->arg.max_eating == -1)
		return (NULL);
	data->arg.max_eating--;
	ft_usleep(10);
	while (1)
	{ 
		i = 0;
		if (check_death(data))
			return (NULL);
		while (i < data->arg.philo_counter)
		{
			if (check_death(data))
				return (NULL);
			if (data->arg.max_eating >= data->philo[i].eating_count)
				break ;
			i++;
		}
		if (i >= data->arg.philo_counter)
			return (condition(data), NULL);
	}
}
