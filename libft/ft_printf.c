/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:34:45 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/09 12:24:54 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(unsigned long address, int chr, int *count)
{
	char	c;

	if (address >= 16)
	{
		if (ft_hexa(address / 16, chr, count) < 0)
			return (-1);
	}
	if (chr == 0)
		c = "0123456789abcdef"[address % 16];
	else if (chr == 1)
		c = "0123456789ABCDEF"[address % 16];
	if (write(1, &c, 1) < 0)
		return (-1);
	(*count)++;
	return (1);
}

int	ft_putnbr(long long n, int *count)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648", count));
		else if (write(1, "-", 1) < 0)
			return (-1);
		(*count)++;
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10, count) < 0)
			return (-1);
	}
	c = (n % 10 + '0');
	if (write(1, &c, 1) < 0)
		return (-1);
	(*count)++;
	return (1);
}

int	conversion_check(const char *c, va_list args, int *count)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(args, int), count));
	else if (*c == 's')
		return (ft_putstr(va_arg(args, char *), count));
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(args, int), count));
	else if (*c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), count));
	else if (*c == '%')
		return (ft_putchar('%', count));
	else if (*c == 'X')
		return (ft_hexa(va_arg(args, unsigned int), 1, count));
	else if (*c == 'x')
		return (ft_hexa(va_arg(args, unsigned int), 0, count));
	else if (*c == 'p')
	{
		if (ft_putstr("0x", count) < 0)
			return (-1);
		return (ft_hexa(va_arg(args, unsigned long), 0, count));
	}
	else
		return (ft_putchar(*c, count));
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		count;

	va_start (args, c);
	count = 0;
	while (*c)
	{
		if (*c == '%')
		{
			if (conversion_check(++c, args, &count) < 0)
				return (-1);
		}
		else if (ft_putchar(*c, &count) < 0)
			return (-1);
		c++;
	}
	va_end (args);
	return (count);
}

//int	main(void)
//{
//	int	a;
//	//int b;

//	a = ft_printf("asdf   %s", "helloo");
//	ft_printf("\n%d\n", a);

//	//b = printf("%s", "");
//	//printf("\n%d\n", b);
//	return (0);
//}
// gcc -Wall -Wextra -Werror ft_printf.c libftprintf.a && ./a.out
