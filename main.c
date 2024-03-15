/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:33:44 by vsoltys           #+#    #+#             */
/*   Updated: 2024/03/15 18:22:21 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>
void *oui(void *args)
{
	(void)args;
	ft_printf("non");
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
	while(argv[i] || i != 5)
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
	if (argv[5])
	{
		data->arg.max_eating = ft_atoi(argv[5]);
	}
}
int main(int argc, char **argv)
{
	pthread_t ouii;
	
	t_data data;
	if (parsing(argc, argv) == 1)
	{
		ft_printf("oui");
		return (1);
	}
	converting_input(argv, &data);
	pthread_create(&ouii, NULL, &oui, NULL);
	ft_printf("apres");
	return (0);
}