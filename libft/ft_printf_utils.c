/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:21:40 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/05 14:49:41 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int *count)
{
	(*count)++;
	return (write(1, &c, 1));
}

int	ft_putstr(char *c, int *count)
{
	int	len;

	len = 0;
	if (c == 0)
	{
		(*count) += 6;
		return (write(1, "(null)", 6));
	}
	while (c[len] != 0)
		len++;
	(*count) += len;
	return (write (1, c, len));
}
