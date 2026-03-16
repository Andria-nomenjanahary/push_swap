/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:26:34 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/07 08:00:02 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_algo_flag(char *arg)
{
	if (!ft_strncmp(arg, "--simple", ft_strlen(arg)))
		return (1);
	if (!ft_strncmp(arg, "--medium", ft_strlen(arg)))
		return (1);
	if (!ft_strncmp(arg, "--complex", ft_strlen(arg)))
		return (1);
	if (!ft_strncmp(arg, "--adaptive", ft_strlen(arg)))
		return (1);
	return (0);
}

static int	count_algo_flags(int ac, char **av)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < ac)
	{
		if (is_algo_flag(av[i]))
			count++;
		i++;
	}
	return (count);
}

static int	count_bench_flags(int ac, char **av)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < ac)
	{
		if (is_bench_flag(av[i]))
			count++;
		i++;
	}
	return (count);
}

int	validate_options(int ac, char **av)
{
	int	algo_count;
	int	bench_count;

	bench_count = count_bench_flags(ac, av);
	algo_count = count_algo_flags(ac, av);
	if (algo_count > 1)
		return (0);
	if (bench_count > 1)
		return (0);
	return (1);
}

int	init_options(int ac, char **av, int *bench_mode, char **flag, int *count_only)
{
	*flag = NULL;
	*bench_mode = 0;
	*count_only = 0;

	if (ac <= 1)
		return (0);
	if (!validate_options(ac, av))
		return (-2);
	if (has_options_between_numbers(ac, av))
		return (-2);
	scan_options(ac, av, bench_mode, flag, count_only);
	return (find_first_number_index(ac, av));
}
