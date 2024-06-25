/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:26:39 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/26 20:53:17 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	a = 0;
	while (a < len)
	{
		ptr[a] = (unsigned char) c;
		a++;
	}
	return (b);
}
