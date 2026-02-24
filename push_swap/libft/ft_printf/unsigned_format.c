/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:37:23 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/06 19:04:51 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_format(unsigned int nbr)
{
	char	c;
	long	int_max;

	int_max = 4294967295;
	if (nbr < 0)
	{
		ft_putnbr_fd(int_max, 1);
		return (int_len(int_max));
	}
	if (nbr >= 10)
		unsigned_format(nbr / 10);
	c = (nbr % 10) + '0';
	ft_putchar_fd(c, 1);
	return (int_len(nbr));
}
