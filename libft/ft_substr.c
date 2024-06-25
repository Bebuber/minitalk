/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:41:04 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 18:20:32 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c1;
	size_t	n;

	n = ft_strlen(s);
	if (len == 0 || start >= n)
	{
		c1 = (char *)malloc(1);
		if (c1 == NULL)
			return (NULL);
		c1[0] = '\0';
		return (c1);
	}
	if (n - start < len)
		len = n - start;
	c1 = (char *)malloc(len + 1);
	if (c1 == NULL)
		return (NULL);
	s = s + start;
	if (len != 0)
		ft_strlcpy(c1, s, len + 1);
	return (c1);
}
