/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:06:21 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 16:49:15 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

static int	init_vars(int ac, char **av, char **flag, int *bench_mode)
{
	int	i;

	*flag = NULL;
	*bench_mode = 0;
	i = 1;
	if (ac < 2)
		return (print_error(), -1);
	if (!ft_strcmp(av[1], "--bench"))
	{
		*bench_mode = 1;
		i = 2;
		if (i < ac && is_valid_flag(av[i]))
			*flag = av[i++];
	}
	else if (is_valid_flag(av[1]))
	{
		*flag = av[1];
		i = 2;
	}
	if (i >= ac)
		return (print_error(), -1);
	return (i);
}

static char	*get_strategy_name(char *flag, float disorder)
{
	if (flag)
	{
		if (!ft_strcmp(flag, "--simple"))
			return ("Simple / O(n²)");
		if (!ft_strcmp(flag, "--medium"))
			return ("Medium / O(n√n)");
		if (!ft_strcmp(flag, "--complex"))
			return ("Complex / O(n log n)");
	}
	if (disorder < 0.2)
		return ("Adaptive (Simple) / O(n²)");
	if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive (Medium) / O(n√n)");
	return ("Adaptive (Complex) / O(n log n)");
}

static void	run_benchmark(t_node **a, t_node **b, char *flag)
{
	t_bench	bench;
	float	disorder;
	char	*strategy;

	init_bench(&bench);
	disorder = compute_disorder(a);
	strategy = get_strategy_name(flag, disorder);
	if (flag)
		exec_algo(flag, a, b, &bench);
	else
		ft_adaptive_algo(a, b, &bench);
	print_bench(&bench, disorder, strategy);
}

static int	parse_and_check(int ac, char **av, int i, t_node **a)
{
	int	num_count;

	num_count = count_total_numbers(ac, av, i);
	if (num_count <= 0)
		return (print_error(), -1);
	if (!parse_args(ac, av, i, a))
	{
		free_stack(a);
		return (print_error(), -1);
	}
	if (check_duplicates(*a))
	{
		free_stack(a);
		return (print_error(), -1);
	}
	return (num_count);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*flag;
	int		i;
	int		bench_mode;

	a = NULL;
	b = NULL;
	i = init_vars(ac, av, &flag, &bench_mode);
	if (i == -1 || parse_and_check(ac, av, i, &a) <= 0)
		return (1);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	if (bench_mode)
		run_benchmark(&a, &b, flag);
	else
	{
		if (flag)
			exec_algo(flag, &a, &b, NULL);
		else
			ft_adaptive_algo(&a, &b, NULL);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
