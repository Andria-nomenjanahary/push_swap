/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:39:12 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/07 08:15:15 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bench_flag(char *arg)
{
	return (ft_strncmp(arg, "--bench", ft_strlen(arg)) == 0);
}

int	is_count_only_flag(char *arg)
{
	return (ft_strncmp(arg, "--count_only", ft_strlen(arg)) == 0);
}

void	process_option(char *arg, int *bench_mode, char **flag, int *count_only)
{
	if (is_count_only_flag(arg))
		*count_only = 1;
	else if (is_bench_flag(arg))
		*bench_mode = 1;
	else if (is_valid_flag(arg))
		*flag = arg;
}

void	scan_options(int ac, char **av, int *bench_mode, char **flag, int *count_only)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		process_option(av[i], bench_mode, flag, count_only);
		i++;
	}
}

int	find_first_number_index(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_bench_flag(av[i]) && !is_valid_flag(av[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	has_options_after_numbers(int ac, char **av, int start_idx)
{
	int	i;

	i = start_idx;
	while (i < ac)
	{
		if (is_valid_flag(av[i]))
			return (1);
		i++;
	}
	return (0);
}
