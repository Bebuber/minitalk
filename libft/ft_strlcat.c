/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:30:03 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 21:00:20 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	m;
	size_t	k;

	i = 0;
	k = 0;
	while (dest[i] != 0)
		i++;
	m = i;
	while (src[k] != 0)
		k++;
	if (size <= i)
		return (size + k);
	n = 0;
	while (src[n] != 0 && n < (size - m - 1))
	{
		dest[i] = src[n];
		n++;
		i++;
	}
	dest[i] = 0;
	return (m + k);
}
