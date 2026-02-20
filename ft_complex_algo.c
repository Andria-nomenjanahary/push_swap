/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:23:56 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 16:35:59 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_node *stack, int target_value)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->value < target_value)
			count++;
		stack = stack->next;
	}
	return (count);
}

static void	normalize_to_indices(t_node **stack)
{
	t_node	*current;
	int		original_value;
	int		index;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		original_value = current->value;
		index = count_smaller(*stack, original_value);
		current->value = index;
		current = current->next;
	}
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_bit(t_node **a, t_node **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*a)->value >> bit) & 1) == 1)
			ft_ra(a);
		else
			ft_pb(b, a);
		i++;
	}
	while (*b)
		ft_pa(a, b);
}

void	ft_complex_algo(t_node **a, t_node **b)
{
	int	bit;
	int	max_bits;
	int	size;

	if (!a || !*a)
		return ;
	size = count_stack(a);
	if (size <= 1)
		return ;
	normalize_to_indices(a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit, size);
		bit++;
	}
}
