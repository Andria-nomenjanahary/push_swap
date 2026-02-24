/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:07:10 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 11:08:31 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_flag(char *arg)
{
	if (!ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium"))
		return (1);
	if (!ft_strcmp(arg, "--complex") || !ft_strcmp(arg, "--adaptive"))
		return (1);
	return (0);
}

static int	check_overflow(char *str, int sign)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > 2147483647)
			return (0);
		if (sign == -1 && num > 2147483648)
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
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[0] == '-')
		sign = -1;
	else
		sign = 1;
	return (check_overflow(str, sign));
}
