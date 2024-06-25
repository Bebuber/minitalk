/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:44:18 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 13:58:05 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_size(long nb)
{
	long	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	else if (nb == 0)
		size++;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_arr(char *num, long nb, long b, int n)
{
	if (n < 0)
		nb = -nb;
	while (nb > 0)
	{
		num[b] = nb % 10 + '0';
		nb = nb / 10;
		b--;
	}
	if (b == 0 && n < 0)
	{
		num[b] = '-';
		b--;
	}
	else if (nb == 0 && b == 0)
	{
		num[b] = '0';
		b--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	long	size;
	long	nb;
	long	b;

	nb = n;
	size = ft_size(nb);
	num = (char *)malloc((size + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	b = size;
	if (b != 0)
	{
		num[b] = '\0';
		b--;
	}
	num = ft_arr(num, nb, b, n);
	return (num);
}
