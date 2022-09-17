/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:24:06 by aozcelik          #+#    #+#             */
/*   Updated: 2022/05/25 12:51:02 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>

int		ft_printf(const	char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr_unsgnd(unsigned int n);
int		ft_putnbr(int n);
int		ft_atoi(const char *s);
int		ft_putstr(char *s);

#endif
