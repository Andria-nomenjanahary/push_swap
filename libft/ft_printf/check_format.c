/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:32:02 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/10 14:39:22 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	string_format(char c, va_list args)
{
	char	*notnull;

	if (c == 's')
	{
		notnull = va_arg(args, char *);
		if (!notnull)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		return (ft_putstr_and_count(notnull));
	}
	return (0);
}

static int	char_format(va_list args)
{
	char	n;

	n = (char)va_arg(args, int);
	ft_putchar_fd(n, 1);
	return (1);
}

static int	libft_functions(char c, va_list args)
{
	if (c == 'c')
		return (char_format(args));
	if (c == 's')
		return (string_format(c, args));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_and_count(va_arg(args, int)));
	return (0);
}

static int	hexa_pointer_functions(char c, va_list args)
{
	void	*notzero;

	if (c == 'u')
		return (unsigned_format(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex_and_count((size_t)va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex_and_count((size_t)va_arg(args, unsigned int), 1));
	if (c == 'p')
	{
		notzero = va_arg(args, void *);
		if (!notzero)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		return (pointer_format(notzero));
	}
	return (0);
}

int	check_format(char c, va_list args)
{
	int	count_libft;
	int	count_hexptr;

	count_libft = libft_functions(c, args);
	count_hexptr = hexa_pointer_functions(c, args);
	if (count_libft)
		return (count_libft);
	if (count_hexptr)
		return (count_hexptr);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
