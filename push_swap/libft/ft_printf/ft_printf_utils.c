/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:17:12 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/10 14:19:00 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

long	ft_putnbr_and_count(int n)
{
	unsigned long	len;

	len = int_len(n);
	ft_putnbr_fd(n, 1);
	return (len);
}

int	ft_putstr_and_count(char *s)
{
	int	len;

	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}

int	ft_puthex_and_count(size_t n, int uppercase)
{
	hexa_format(n, uppercase);
	return (hex_len(n));
}
