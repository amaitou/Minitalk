/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:56:15 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/05 15:50:13 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int signo)
{
	if (signo == SIGUSR1)
		ft_putstr("[*] Message was sent successfully !\n");
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
	{
		ft_putstr("[!] Missing Arguments\n");
		return (0);
	}
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, (void *)0);
	if (ft_atoi(ag[1]) <= 0)
	{
		ft_putstr("[!] Invalid Process Id\n");
		return (0);
	}
	ft_client(ft_atoi(ag[1]), ag[2]);
	return (0);
}
