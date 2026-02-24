/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:59:15 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/03 10:48:00 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t		i;
	size_t		dlen;
	size_t		slen;

	dlen = 0;
	slen = 0;
	i = 0;
	while (src[i])
	{
		slen++;
		i++;
	}
	while (dlen < dsize && dst[dlen] != '\0')
		dlen++;
	if (dlen == dsize)
		return (slen + dsize);
	i = 0;
	while (src[i] != '\0' && (dlen + i + 1) < dsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
