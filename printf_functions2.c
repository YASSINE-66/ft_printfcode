/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:07:11 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/12/23 01:50:19 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		count++;
		write(1, s++, 1);
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putxx(unsigned int nb, char c)
{
	char	*s;
	int		count;

	s = NULL;
	count = 0;
	if (c == 'x')
		s = "0123456789abcdef";
	else if (c == 'X')
		s = "0123456789ABCDEF";
	if (nb > 15)
		count += ft_putxx(nb / 16, c);
	count += ft_putchar(s[nb % 16]);
	return (count);
}
