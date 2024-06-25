/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:33:55 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/26 16:40:02 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		start;
	int		end;
	size_t	len;
	char	*result;

	c = 0;
	while (s1[c] && ft_strchr(set, s1[c]) != 0)
		c++;
	start = c;
	end = start;
	while (s1[c])
	{
		if (ft_strchr(set, s1[c]) == 0)
		{
			c++;
			end = c;
		}
		else
			c++;
	}
	len = end - start;
	result = ft_substr(s1, start, len);
	return (result);
}
