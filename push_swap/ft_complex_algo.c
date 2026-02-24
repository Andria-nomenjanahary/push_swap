/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:05:33 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 16:02:21 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

void	quick_sort(int *arr, int low, int high)
{
	int	p_idx;

	if (low < high)
	{
		p_idx = partition(arr, low, high);
		quick_sort(arr, low, p_idx - 1);
		quick_sort(arr, p_idx + 1, high);
	}
}

static void	normalize_to_indices(t_node **stack, int size)
{
	int	*tmp;

	tmp = get_sorted_array(*stack, size);
	if (!tmp)
		return ;
	assign_indices(stack, tmp, size);
	free(tmp);
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_bit(t_node **a, t_node **b, int bit, t_bench *bench)
{
	int	i;
	int	size;

	i = 0;
	size = count_stack(a);
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 1)
			ft_ra(a, bench);
		else
			ft_pb(b, a, bench);
		i++;
	}
	while (*b)
		ft_pa(a, b, bench);
}

void	ft_complex_algo(t_node **a, t_node **b, t_bench *bench)
{
	int	bit;
	int	max_bits;
	int	size;

	if (!a || !*a)
		return ;
	size = count_stack(a);
	if (size <= 1)
		return ;
	normalize_to_indices(a, size);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit, bench);
		bit++;
	}
}
