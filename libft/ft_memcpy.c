/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:54:03 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 20:37:59 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	a;

	a = 0;
	if (dst == 0 && src == 0)
		return (dst);
	while (a < len)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dst);
}
