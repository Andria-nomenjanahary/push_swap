/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:04:31 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/03 08:08:52 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy(char *dest, const char *src, int *i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[*i] = src[j];
		(*i)++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = malloc((s1len + s2len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	copy(res, s1, &i);
	copy(res, s2, &i);
	res[i] = '\0';
	return (res);
}
