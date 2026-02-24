/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:41:53 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/09 17:02:46 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pointer_format(void *ptr)
{
	size_t	addr;

	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	addr = (size_t)ptr;
	hexa_format(addr, 0);
	return (hex_len(addr) + 2);
}
