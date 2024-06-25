/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:17:33 by bebuber           #+#    #+#             */
/*   Updated: 2024/03/28 17:21:31 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_rows(const char *s, char c)
{
	int	rows;
	int	n;

	n = 0;
	rows = 0;
	while (s[n] != '\0')
	{
		if (n == 0 && s[n] != c && s[n] != 0)
		{
			rows++;
			n++;
		}
		else if (s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
		{
			rows++;
			n++;
		}
		else
			n++;
	}
	return (rows);
}

static int	ft_size_cols(const char *s, char c, int n)
{
	int	size;

	size = 0;
	while (s[n] != c && s[n])
	{
		size ++;
		n++;
	}
	return (size);
}

static char	**ft_free_return_null(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		rows;
	int		size;
	int		n;
	int		p;

	rows = ft_count_rows(s, c);
	arr = (char **)ft_calloc((rows + 1), sizeof(char *));
	if (arr == NULL)
		return (NULL);
	n = 0;
	p = 0;
	while (p < rows)
	{
		while (s[n] == c)
			n++;
		size = ft_size_cols(s, c, n);
		arr[p] = ft_substr(s, n, size);
		if (arr[p] == NULL)
			return (ft_free_return_null(arr));
		n = size + n;
		p++;
	}
	arr[p] = 0;
	return (arr);
}

//int	main(void)
//{
//	char	**arr;
//	int		n;
//	int		i;
//	char	const *s = "hello!zzzzzzzz";
//	char	c = 'z';

//	n = 0;
//	i = 0;
//	arr = ft_split(s, c);
//	while (arr[n])
//	{
//		while (arr[n][i])
//		{
//			printf ("arr[%d] [%d] = %c \n",n,i, arr[n][i]);
//			i++;
//		}
//		n++;
//		i = 0;
//	}
//	return (0);
//}
