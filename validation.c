/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:07:10 by ainradan          #+#    #+#             */
/*   Updated: 2026/03/07 08:03:41 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	is_valid_flag(char *arg)
{
	if (!ft_strncmp(arg, "--simple", ft_strlen(arg)) || !ft_strncmp(arg,
			"--medium", ft_strlen(arg)))
		return (1);
	if (!ft_strncmp(arg, "--complex", ft_strlen(arg)) || !ft_strncmp(arg,
			"--adaptive", ft_strlen(arg)))
		return (1);
	if (!ft_strncmp(arg, "--count_only", ft_strlen(arg)))
		return (1);
	return (0);
}

static int	check_overflow(char *str, int sign)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > 2147483647LL)
			return (0);
		if (sign == -1 && num > 2147483648LL)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;
	int	sign;

	i = 0;
	if (!str || !str[0])
		return (0);
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		return (0);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (check_overflow(str, sign));
}
