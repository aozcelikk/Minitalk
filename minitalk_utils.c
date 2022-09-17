/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:25:03 by aozcelik          #+#    #+#             */
/*   Updated: 2022/05/25 12:50:14 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	int				nm;
	long long int	tmp;

	nm = 1;
	tmp = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			nm = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		tmp = (tmp * 10) + (*s - '0') * nm;
		s++;
		if (tmp > 2147483647)
			return (-1);
		if (tmp < -2147483648)
			return (0);
	}
	return (tmp);
}
