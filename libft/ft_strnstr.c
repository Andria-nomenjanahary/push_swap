/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 07:38:18 by yvoandri          #+#    #+#             */
/*   Updated: 2026/01/29 08:25:24 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *title, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ubig;
	char	*utitle;

	ubig = (char *)big;
	utitle = (char *)title;
	i = 0;
	if (utitle[i] == '\0')
		return (ubig);
	while (i < len && ubig[i])
	{
		j = 0;
		while (utitle[j] && i + j < len && ubig[i + j] == utitle[j])
		{
			if (utitle[j + 1] == '\0')
				return (&ubig[i]);
			j++;
		}
		if (utitle[j] == '\0')
			break ;
		i++;
	}
	return (NULL);
}
