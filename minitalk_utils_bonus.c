/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:45:52 by amait-ou          #+#    #+#             */
/*   Updated: 2022/12/31 22:51:01 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		++s;
	}
}

int	ft_power(int nb, int power)
{
	int	r;

	if (power < 0)
		return (0);
	r = 1;
	while (power-- > 0)
		r *= nb;
	return (r);
}

void	ft_putnbr(int n)
{
	char	a;
	char	b;

	if (n >= 0 && n <= 9)
	{
		a = n + 48 ;
		write(1, &a, 1);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		b = '-';
		write(1, &b, 1);
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_sender(pid_t pid, char c)
{
	int	bits;
	int	kill_status;

	bits = 0b10000000;
	while (bits)
	{
		if (c & bits)
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
}
