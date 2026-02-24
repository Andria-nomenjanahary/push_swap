/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:06:16 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 15:36:05 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

void	exec_algo(char *flag, t_node **a, t_node **b, t_bench *bench)
{
	if (!ft_strcmp(flag, "--simple"))
		ft_simple_algo(a, b, bench);
	else if (!ft_strcmp(flag, "--medium"))
		ft_medium_algo(a, b, bench);
	else if (!ft_strcmp(flag, "--complex"))
		ft_complex_algo(a, b, bench);
	else
		ft_adaptive_algo(a, b, bench);
}

void	ft_rrb(t_node **b, t_bench *bench)
{
	ft_rra_rrb(b);
	write(1, "rrb\n", 4);
	if (bench)
		bench_rrb(bench);
}

void	ft_rra(t_node **a, t_bench *bench)
{
	ft_rra_rrb(a);
	write(1, "rra\n", 4);
	if (bench)
		bench_rra(bench);
}
