/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:32:30 by eseiv             #+#    #+#             */
/*   Updated: 2021/12/04 20:01:37 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *cp);
void	ft_check(va_list args, int i, const char *str, int *len);
void	ft_putstr(char *s, int *cp);
void	ft_putnbr(int nb, int *cp);
void	ft_tohex(unsigned int d, const char *base, int *cp);
void	ft_ptr(unsigned long n, char *base, int *cp);
void	ft_unsigned(unsigned int n, int *cp);
#endif
