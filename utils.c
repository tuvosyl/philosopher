/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:36 by valentins         #+#    #+#             */
/*   Updated: 2024/04/30 16:48:13 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			r = r * 10 + nptr[i] - '0';
		else
			break ;
		i++;
	}
	return (s * r);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long int		actual_time(void)
{
	long int			time;
	struct timeval		current_time;


	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time)
		usleep(time / 10);
}

void	custom_printf(t_philo *philo, char *str, char *color)
{
	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_lock(&philo->data->time_eat);
	if (!ft_strncmp(color, B_GREEN, 10) && philo)
		printf("philo %d as eaten %d times\n", philo->id + 1, philo->eating_count);
	printf("%s%ld %d %s%s\n",color, actual_time() - philo->data->arg.start_time, philo->id + 1, str, RESET);
	pthread_mutex_unlock(&philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->write);
}