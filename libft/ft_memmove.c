/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:52:24 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 21:15:50 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	a = 0;
	if ((dst == src) || len == 0)
		return (dst);
	if (dst < src || dst >= src + len)
	{
		while (a < len)
		{
			((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
			a++;
		}
	}
	else
	{
		a = len - 1;
		while (a < len)
		{
			((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
			a--;
		}
	}
	return (dst);
}
