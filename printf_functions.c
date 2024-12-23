/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:07:06 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/12/19 02:14:01 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned long n)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
		count += ft_convert(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	numlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	int	count;

	count = 0;
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (n < 0)
	{
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (numlen(n));
}

int	ft_putpoi(unsigned long n)
{
	int				count;
	unsigned long	nb;

	nb = n;
	count = 0;
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	return (count += ft_convert(nb));
}
