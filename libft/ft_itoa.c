/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:47:02 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/09 18:47:06 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*fill_tab(char *str, long num, int len)
{
	while (len > 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
		nb = -nb;
	len = count_digits(nb);
	if (n < 0)
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	fill_tab(res, nb, len);
	if (n < 0)
		res[0] = '-';
	return (res);
}
