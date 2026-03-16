/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:45:32 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 11:52:55 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_option_arg(char *arg)
{
	if (is_bench_flag(arg))
		return (1);
	if (is_valid_flag(arg))
		return (1);
	return (0);
}

int	count_numbers_in_arg(char *arg)
{
	int	count;

	count = count_in_str(arg);
	return (count);
}

int	count_total_numbers_skip_options(int ac, char **av, int start_idx)
{
	int	total_count;
	int	current_count;
	int	i;

	total_count = 0;
	i = start_idx;
	while (i < ac)
	{
		if (is_option_arg(av[i]))
		{
			i++;
			continue ;
		}
		current_count = count_numbers_in_arg(av[i]);
		if (current_count == -1)
			return (-1);
		total_count = total_count + current_count;
		i++;
	}
	return (total_count);
}

static int	parse_single_arg(char *arg, t_node **a)
{
	return (parse_str(arg, a));
}

int	parse_args_skip_options(int ac, char **av, int start_idx, t_node **a)
{
	int	i;

	i = start_idx;
	while (i < ac)
	{
		if (is_option_arg(av[i]))
		{
			i++;
			continue ;
		}
		if (!parse_single_arg(av[i], a))
			return (0);
		i++;
	}
	return (1);
}
