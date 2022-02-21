/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:25:45 by eseiv             #+#    #+#             */
/*   Updated: 2021/12/04 22:06:28 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list args, int i, const char *str, int *len)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(args, int ), len);
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int), len);
	if (str[i] == 'x')
		ft_tohex(va_arg(args, unsigned long int), "0123456789abcdef", len);
	if (str[i] == 'X')
		ft_tohex(va_arg(args, unsigned long int), "0123456789ABCDEF", len);
	if (str[i] == '%')
		ft_putchar('%', len);
	if (str[i] == 'p')
	{
		ft_putstr("0x", len);
		ft_ptr(va_arg(args, unsigned long int), "0123456789abcdef", len);
	}
	if (str[i] == 's')
		ft_putstr(va_arg(args, char *), len);
	if (str[i] == 'u')
		ft_unsigned(va_arg(args, unsigned long int ), len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &len);
		else
			ft_check(args, ++i, format, &len);
	}
	va_end(args);
	return (len);
}

// int main()
// {
//    int x = 50;
//    int *ptr = &x;
// ft_printf("%p,%d", ptr,  *ptr);
//     // int i = ft_printf("%\n", 'a');
//     // printf("%c\n", 'a');   
// 	// ft_printf("%c\n", 'a');
//     // ft_printf("%s\n", "seiv"); 
//     // printf("%s\n", "seiv");  
//     // ft_printf("%i\n", i);  
// 	// ft_printf("%i\n", i);
//     // printf("%i\n", 15); 
// 	//  printf("%i\n", 15);  
//     // ft_printf("%d\n", 14);
//     // printf("%d\n", 14);
//     // ft_printf("%x\n", 2021);
//     // printf("%x\n", 2021);
//     // ft_printf("%X\n", 2021);
//     // printf("%X\n", 2021);
//     // ft_printf("%u\n", 1);
//     // printf("%u\n", 1);
// 	//    printf("%p", 20);
// 	//    ft_printf("%p",0x123);
// }
