/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:07:16 by yaaitmou          #+#    #+#             */
/*   Updated: 2024/12/21 23:17:23 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_help
{
	int	i;
	int	lent;
}		t_h;

int		ft_putchar(char c);
int		numlen(int n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		ft_putpoi(unsigned long n);
int		ft_convert(unsigned long n);
int		ft_putxx(unsigned int nb, char c);
int		ft_putunsigned(unsigned int n);

#endif
