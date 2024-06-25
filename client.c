/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:04:01 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/25 17:30:49 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				error("Error: failed to send signal\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error("Error: failed to send signal\n");
		}
		c >>= 1;
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (kill(pid, 0) == -1)
			error("Error: invalid PID\n");
		while (*argv[2])
		{
			send_char(pid, *argv[2]);
			argv[2]++;
			usleep(100);
		}
	}
	else
		error("Usage: ./client [PID] [message]\n");
	return (0);
}
