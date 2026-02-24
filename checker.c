/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:25:52 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/24 15:38:27 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_string(char *str)
{
	int		i;
	int		nb;
	int		count;
	char	*num;

	count = count_numbers(str);
	i = 0;
	while (i < count)
	{
		num = extract_number(str, i);
		if (!num || !is_number(num))
		{
			ft_putstr_fd("Error\n", 2);
			free(num);
			return (-1);
		}
		nb = ft_atoi(num);
		free(num);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ac == 2)
		return (parse_string(av[1]));
	return (parse_checker_args(ac, av));
}
