/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:52:58 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/03 10:32:04 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		uc;

	i = 0;
	uc = (char)c;
	while (s[i])
	{
		if (uc == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
