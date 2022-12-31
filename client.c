/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:21:12 by amait-ou          #+#    #+#             */
/*   Updated: 2022/12/31 18:39:28 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client(pid_t pid, char *s)
{
	int	bits;
	int	kill_status;

	while (*s)
	{
		bits = 0b10000000;
		while (bits)
		{
			if (*s & bits)
			{
				kill_status = kill(pid, SIGUSR2);
				if (kill_status < 0)
					return ;
			}
			else
			{
				kill_status = kill(pid, SIGUSR1);
				if (kill_status < 0)
					return ;
			}
			bits >>= 1;
			usleep(250);
		}
		++s;
	}
}

int	main(int ac, char **ag)
{
	if (ac <= 2)
		return (0);
	ft_client(ft_atoi(ag[1]), ag[2]);
	return (0);
}
