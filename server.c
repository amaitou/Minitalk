/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:29:45 by amait-ou          #+#    #+#             */
/*   Updated: 2022/12/31 19:06:43 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server(int signo, siginfo_t *sig_info, void *context)
{
	static int	i;
	static char	ascii;
	static int	g_pid;

	(void)context;
	signo -= SIGUSR1;
	if (g_pid != sig_info->si_pid)
	{
		ascii = 0;
		i = 0;
		g_pid = sig_info->si_pid;
	}
	ascii += signo * ft_power(2, (7 - i));
	++i;
	if (i == 8)
	{
		ft_putchar(ascii);
		i = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_server;
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
