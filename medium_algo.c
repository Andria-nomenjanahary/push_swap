/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:30:35 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 12:34:54 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "medium_algo.h"
#include "command.h"

void	push_max_to_a(t_node **a, t_node **b, t_bench *bench)
{
	int	max_val_b;
	int	pos;
	int	b_size;

	max_val_b = find_max(b);
	pos = get_pos_in_stack(*b, max_val_b);
	b_size = count_stack(b);
	if (pos <= b_size / 2)
	{
		while ((*b)->value != max_val_b)
			ft_rb(b, bench);
	}
	else
	{
		while ((*b)->value != max_val_b)
			ft_rrb(b, bench);
	}
	ft_pa(a, b, bench);
}

void	init_buckets(t_bucket *buckets, int bucket_count, int min_val,
		int max_val)
{
	int	range;
	int	bucket_size;
	int	remainder;
	int	i;
	int	current_min;

	range = max_val - min_val + 1;
	bucket_size = range / bucket_count;
	remainder = range % bucket_count;
	current_min = min_val;
	i = 0;
	while (i < bucket_count)
	{
		buckets[i].min_val = current_min;
		buckets[i].max_val = current_min + bucket_size - 1;
		if (remainder > 0)
		{
			buckets[i].max_val++;
			remainder--;
		}
		buckets[i].target_count = 0;
		buckets[i].current_count = 0;
		current_min = buckets[i].max_val + 1;
		i++;
	}
}

void	count_buckets(t_node *stack, t_bucket *buckets, int bucket_count)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < bucket_count)
		{
			if (stack->value >= buckets[i].min_val
				&& stack->value <= buckets[i].max_val)
			{
				buckets[i].target_count++;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

int	find_active_bucket(t_bucket *buckets, int bucket_count)
{
	int	i;

	i = 0;
	while (i < bucket_count)
	{
		if (buckets[i].current_count < buckets[i].target_count)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_medium_algo(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = count_stack(a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sort_two(a, bench));
	if (size == 3)
		return (sort_three(a, bench));
	if (size == 4)
		return (sort_four(a, b, bench));
	if (size == 5)
		return (sort_five(a, b, bench));
	sqrt_n_chunk_sort(a, b, bench);
}
