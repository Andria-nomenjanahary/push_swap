/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:30:51 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 12:34:46 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "medium_algo.h"
#include "command.h"

void	find_min_max(t_node *stack, int *min, int *max)
{
	*min = stack->value;
	*max = stack->value;
	while (stack)
	{
		if (stack->value < *min)
			*min = stack->value;
		if (stack->value > *max)
			*max = stack->value;
		stack = stack->next;
	}
}

void	sort_two(t_node **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, bench);
}

void	sort_three(t_node **a, t_bench *bench)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = (*a)->value;
	v2 = (*a)->next->value;
	v3 = (*a)->next->next->value;
	if (v1 > v2 && v2 < v3 && v1 < v3)
		ft_sa(a, bench);
	else if (v1 > v2 && v2 > v3)
	{
		ft_sa(a, bench);
		ft_rra(a, bench);
	}
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		ft_ra(a, bench);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		ft_sa(a, bench);
		ft_ra(a, bench);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		ft_rra(a, bench);
}

void	sort_four(t_node **a, t_node **b, t_bench *bench)
{
	int	min;
	int	pos;
	int	size;

	min = find_min(a);
	pos = get_pos_in_stack(*a, min);
	size = count_stack(a);
	if (pos <= size / 2)
		while ((*a)->value != min)
			ft_ra(a, bench);
	else
		while ((*a)->value != min)
			ft_rra(a, bench);
	ft_pb(b, a, bench);
	sort_three(a, bench);
	ft_pa(a, b, bench);
}

void	sort_five(t_node **a, t_node **b, t_bench *bench)
{
	int	pushed;
	int	min;
	int	pos;
	int	size;

	pushed = 0;
	while (count_stack(a) > 3 && pushed < 2)
	{
		min = find_min(a);
		pos = get_pos_in_stack(*a, min);
		size = count_stack(a);
		if (pos <= size / 2)
			while ((*a)->value != min)
				ft_ra(a, bench);
		else
			while ((*a)->value != min)
				ft_rra(a, bench);
		ft_pb(b, a, bench);
		pushed++;
	}
	sort_three(a, bench);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		ft_sb(b, bench);
	while (*b)
		ft_pa(a, b, bench);
}
