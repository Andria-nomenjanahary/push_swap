/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:56:09 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/03 07:48:22 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*copy(char *dest, const char *src, int start, int end)
{
	int	i;

	i = 0;
	while (src[i] && start <= end)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*res;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && check(s1[i], set))
	{
		start++;
		i++;
	}
	end = ft_strlen(s1);
	end--;
	while (end >= start && check(s1[end], set))
		end--;
	res = malloc((end - start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	copy(res, s1, start, end);
	return (res);
}
