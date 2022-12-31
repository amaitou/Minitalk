/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonuc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:21:12 by amait-ou          #+#    #+#             */
/*   Updated: 2022/12/31 22:28:30 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void handler(int signo)
{
	if (signo == 30)
		ft_putstr("signal has been received successefully\n");
		exit(0);
}

void	ft_client(pid_t pid, char *s)
{
	int		bits;
	int		kill_status;
	char	c;

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
	c = '\0';
	bits = 0b10000000;
	while (bits)
	{
		kill_status = kill(pid, SIGUSR1);
		bits >>= 1;
		usleep(250);
	}
}

int	main(int ac, char **ag)
{
	struct sigaction sa;
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac <= 2)
		return (0);
	ft_client(ft_atoi(ag[1]), ag[2]);
	while (1)
		pause();
	return (0);
}
