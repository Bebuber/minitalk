/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:03:03 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 18:29:28 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	check;
	void	*ptr;

	check = count * size;
	if (size != 0 && check / size != count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr != 0)
		ft_memset(ptr, 0, count * size);
	return (ptr);
}
