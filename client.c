/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:56:15 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/05 15:49:58 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client(pid_t pid, char *s)
{
	while (*s)
	{
		ft_sender(pid, *s);
		++s;
	}
}

int	main(int ac, char **ag)
{
	if (ac <= 2)
	{
		ft_putstr("[!] Missing Arguments\n");
		return (0);
	}
	if (ft_atoi(ag[1]) <= 0)
	{
		ft_putstr("[!] Invalid Process Id\n");
		return (0);
	}
	ft_client(ft_atoi(ag[1]), ag[2]);
	return (0);
}
