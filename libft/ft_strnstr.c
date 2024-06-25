/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:11:45 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 21:09:28 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != 0 && len > 0)
	{
		n = 0;
		while (haystack[i + n] == needle[n] && needle[n] != 0 && n < len)
			n++;
		if (needle[n] == 0)
			return ((char *)haystack + i);
		i++;
		len--;
	}
	return (0);
}
