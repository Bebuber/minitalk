/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:04:12 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/25 17:33:38 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_handler(int signal)
{
	static int		c = 0;
	static char		letter = 0;

	if (signal == SIGUSR2)
		letter |= (1 << c);
	c++;
	if (c == 8)
	{
		write(1, &letter, 1);
		c = 0;
		letter = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
		error("Usage: ./server\n");
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
