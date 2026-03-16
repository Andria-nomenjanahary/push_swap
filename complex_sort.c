/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:04:41 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/05 14:04:43 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "complex_algo.h"

void	sort_two_complex(t_node **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, bench);
}

void	sort_three_complex(t_node **a, t_bench *bench)
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

void	sort_four_complex(t_node **a, t_node **b, t_bench *bench)
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
	sort_three_complex(a, bench);
	ft_pa(a, b, bench);
}

void	sort_five_complex(t_node **a, t_node **b, t_bench *bench)
{
	int	min;
	int	pos;
	int	size;
	int	pushed;

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
	sort_three_complex(a, bench);
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		ft_sb(b, bench);
	while (*b)
		ft_pa(a, b, bench);
}
