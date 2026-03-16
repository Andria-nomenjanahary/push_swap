/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:55:59 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/06 09:57:02 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "command.h"
#include "complex_algo.h"

void	radix_lsd_sort(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	max_bits;
	int	bit;
	int	i;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				ft_pb(b, a, bench);
			else
				ft_ra(a, bench);
			i++;
		}
		while (*b)
			ft_pa(a, b, bench);
		bit++;
	}
}

void	ft_complex_algo(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	*tmp;

	if (!a || !*a)
		return ;
	size = count_stack(a);
	if (size == 1)
		return ;
	if (size == 2)
		return (sort_two_complex(a, bench));
	if (size == 3)
		return (sort_three_complex(a, bench));
	if (size == 4)
		return (sort_four_complex(a, b, bench));
	if (size == 5)
		return (sort_five_complex(a, b, bench));
	tmp = get_sorted_array(*a, size);
	if (!tmp)
		return ;
	assign_indices(a, tmp, size);
	free(tmp);
	radix_lsd_sort(a, b, size, bench);
}
