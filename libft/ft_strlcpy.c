/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:47:34 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 20:47:49 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (src[i] != 0)
		i++;
	if (dest == 0 || size == 0)
		return (i);
	while ((s < size - 1) && (src[s] != 0))
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = 0;
	return (i);
}
