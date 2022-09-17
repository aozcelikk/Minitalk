/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:18:45 by aozcelik          #+#    #+#             */
/*   Updated: 2022/05/25 12:52:54 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_set_bit(int x)
{
	static int	bit = 7;
	static int	set = 0;

	set += x << bit;
	if (bit == 0)
	{
		write(1, &set, 1);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	ft_sgl_catch(int x)
{
	if (x == SIGUSR1)
		ft_set_bit(1);
	else if (x == SIGUSR2)
		ft_set_bit(0);
}

int	main(void)
{
	ft_printf("PID: %u\n", getpid());
	signal(SIGUSR1, ft_sgl_catch);
	signal(SIGUSR2, ft_sgl_catch);
	while (1)
		pause();
}
