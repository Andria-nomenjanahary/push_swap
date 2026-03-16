/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:55:33 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 16:45:34 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_one_number(char **argv, int *i, t_node **stack_a)
{
	int	num;

	if (!argv[*i] || !is_number(argv[*i]))
		return (1);
	num = ft_atoi(argv[*i]);
	add_back(stack_a, new_node(num));
	*i = *i + 1;
	return (0);
}

int	is_number_string(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (i > 0 && !(arg[0] == '-' && !arg[1]));
}

int	has_options_between_numbers(int ac, char **av)
{
	int	i;
	int	found_number;
	int	found_option_after_number;

	found_number = 0;
	found_option_after_number = 0;
	i = 1;
	while (i < ac)
	{
		if (is_number_string(av[i]))
		{
			if (found_option_after_number)
				return (1);
			found_number = 1;
		}
		else if (is_algo_flag(av[i]) || is_bench_flag(av[i]))
		{
			if (found_number)
				found_option_after_number = 1;
		}
		i++;
	}
	return (0);
}
