/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:22:39 by aozcelik          #+#    #+#             */
/*   Updated: 2022/05/16 14:22:42 by aozcelik         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putstr(char *s)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[idx] != '\0')
	{
		cnt += write(1, &s[idx], 1);
		idx++;
	}
	return (cnt);
}

int	ft_putnbr_unsgnd(unsigned int n)
{
	int				cnt;
	unsigned int	i;
	char			str[10];

	cnt = 0;
	i = 0;
	if (n == 0)
		cnt += ft_putchar('0');
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		cnt += ft_putchar(str[i]);
	return (cnt);
}

int	ft_putchar(char c)
{
	int	cnt;

	cnt = 0;
	cnt += write(1, &c, 1);
	return (cnt);
}

int	type_srch(va_list vag, char str, int a)
{
	if (str == 'u')
		a = ft_putnbr_unsgnd(va_arg(vag, unsigned int));
	else if (str == 's')
		a = ft_putstr(va_arg(vag, char *));
	return (a);
}

int	ft_printf(const char *s, ...)
{
	int		a;
	va_list	vag;

	a = 0;
	va_start(vag, s);
	while (*s)
	{
		if (*s == '%')
			a += type_srch(vag, *(++s), a);
		else
			a += ft_putchar(*s);
		s++;
	}
	va_end(vag);
	return (a);
}
