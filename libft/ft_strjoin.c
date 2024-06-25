/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:12:00 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/17 17:38:43 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		a;
	int		i;
	char	*new;

	a = 0;
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[a] != 0)
	{
		new[i] = s2[a];
		i++;
		a++;
	}
	new[i] = '\0';
	free((char *)s1);
	return (new);
}
