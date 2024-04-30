/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:53 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/30 17:08:40 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n )
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	norme(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->arg.philo_counter);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->arg.philo_counter);
	data->dead_flag = false;
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->eating_count, NULL);
	pthread_mutex_init(&data->time_eat, NULL);
	pthread_mutex_init(&data->write, NULL);
}
