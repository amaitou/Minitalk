/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:56:15 by amait-ou          #+#    #+#             */
/*   Updated: 2022/12/31 23:09:14 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int signo)
{
	if (signo == SIGUSR1)
		ft_putstr("signal has been received successefully\n");
	exit(0);
}

void	ft_client(pid_t pid, char *s)
{
	while (*s)
	{
		ft_sender(pid, *s);
		++s;
	}
	ft_sender(pid, '\0');
}

int	main(int ac, char **ag)
{
	struct sigaction	sa;

	if (ac <= 2)
		return (0);
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	ft_client(ft_atoi(ag[1]), ag[2]);
	return (0);
}