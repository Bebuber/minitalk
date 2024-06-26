/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:07:22 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 20:32:15 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	if_number(const char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	return (0);
}

void	if_negative(const char *str, int *i, int *ngt)
{
	if (str[*i] == '-')
	{
		(*ngt) = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		(*ngt) = 1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ngt;
	int	numb;

	i = 0;
	ngt = 1;
	numb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if_negative(str, &i, &ngt);
	while (if_number(str[i]) == 1)
	{
		numb = numb * 10;
		numb = numb + (str[i] - '0');
		i++;
	}
	return (numb * ngt);
}

//int	main(void)
//{
//	char str[] = "	--2143647";

//	printf("%d", ft_atoi(str));
//	return (0);
//}