/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:08:34 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 13:33:26 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		stack = stack->next;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_rra(t_node	**a)
{
	ft_rra_rrb(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node	**b)
{
	ft_rra_rrb(b);
	write(1, "rrb\n", 4);
}

void	ft_rb(t_node **b)
{
	ft_ra_rb(b);
	write(1, "rb\n", 3);
}

int	get_pos_in_stack(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}
