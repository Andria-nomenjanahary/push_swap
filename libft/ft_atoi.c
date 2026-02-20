/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:00:13 by yvoandri          #+#    #+#             */
/*   Updated: 2026/01/21 09:47:05 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *npt)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*npt == 32 || (*npt >= 9 && *npt <= 13))
		npt++;
	if (*npt == '+' || *npt == '-')
	{
		if (*npt == '-')
			sign = sign * -1;
		npt++;
	}
	while (*npt >= '0' && *npt <= '9')
	{
		result = (result * 10) + (*npt - '0');
		npt++;
	}
	return (result * sign);
}
