/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:47:14 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/03 10:35:07 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		upc;

	p = (const unsigned char *)s;
	upc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == upc)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
