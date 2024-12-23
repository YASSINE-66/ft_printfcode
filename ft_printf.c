/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:11:37 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/12/19 19:55:28 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_man(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(arg, int));
	else if (c == '%')
		count = ft_putchar('%');
	else if (c == 'p')
		count += ft_putpoi(va_arg(arg, unsigned long));
	else if (c == 'x' || c == 'X')
		count = ft_putxx(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		count = ft_putunsigned(va_arg(arg, unsigned int));
	else
		count = ft_putchar('%') + ft_putchar(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_h		helper;
	va_list	arg;

	helper.i = 0;
	helper.lent = 0;
	va_start(arg, format);
	if (format == NULL)
		return (-1);
	while (format[helper.i])
	{
		if (format[helper.i] == '%')
		{
			helper.i++;
			if (format[helper.i] == '\0')
				return (-1);
			helper.lent += ft_man(arg, format[helper.i]);
		}
		else
			helper.lent += ft_putchar(format[helper.i]);
		helper.i++;
	}
	va_end(arg);
	return (helper.lent);
}
