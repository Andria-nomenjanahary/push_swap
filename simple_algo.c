/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:20:33 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 12:35:19 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"
#include "command.h"

static void	sort_three(t_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		ft_sa(a, bench);
	else if (first > second && second > third)
	{
		ft_sa(a, bench);
		ft_rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ft_ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		ft_sa(a, bench);
		ft_ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		ft_rra(a, bench);
}

static void	sort_small(t_node **a, t_node **b, t_bench *bench)
{
	int	min;

	while (count_stack(a) > 3)
	{
		min = find_min(a);
		while ((*a)->value != min)
		{
			if (get_pos_in_stack(*a, min) <= count_stack(a) / 2)
				ft_ra(a, bench);
			else
				ft_rra(a, bench);
		}
		ft_pb(b, a, bench);
	}
	sort_three(a, bench);
	while (*b)
		ft_pa(a, b, bench);
}

void	ft_simple_algo(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;

	size = count_stack(stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a, bench);
	}
	else if (size == 3)
		sort_three(stack_a, bench);
	else
		sort_small(stack_a, stack_b, bench);
}
