/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:58:32 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 09:37:10 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		ft_sa(a);
	else if (first > second && second > third)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (first > second && second < third && first > third)
		ft_ra(a);
	else if (first < second && second > third && first < third)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (first < second && second > third && first > third)
		ft_rra(a);
}

static void	sort_small(t_node **a, t_node **b)
{
	int	min;

	while (count_stack(a) > 3)
	{
		min = find_min(a);
		while ((*a)->value != min)
		{
			if (get_pos_in_stack(*a, min) <= count_stack(a) / 2)
				ft_ra(a);
			else
				ft_rra(a);
		}
		ft_pb(b, a);
	}
	sort_three(a);
	while (*b)
		ft_pa(a, b);
}

void	ft_simple_algo(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = count_stack(stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_small(stack_a, stack_b);
}
