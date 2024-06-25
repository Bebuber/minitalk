/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:43:06 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 20:31:12 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = 0;
	c = (char) c;
	while (s[n] != 0)
		n++;
	while (n >= 0)
	{
		if (s[n] == c)
		{
			s = s + n;
			return ((char *)s);
		}
		n--;
	}
	return (0);
}
