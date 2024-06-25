/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:03:09 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 15:01:29 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*final;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
