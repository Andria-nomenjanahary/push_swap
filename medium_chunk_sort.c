/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:23:28 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 12:53:56 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "medium_algo.h"
#include "command.h"

static int	find_pos_in_bucket(t_node *stack, t_bucket *bucket)
{
	int	pos;
	int	idx;

	pos = -1;
	idx = 0;
	while (stack)
	{
		if (stack->value >= bucket->min_val && stack->value <= bucket->max_val)
		{
			pos = idx;
			break ;
		}
		idx++;
		stack = stack->next;
	}
	return (pos);
}

static void	rotate_to_pos(t_node **a, int pos, int size, t_bench *bench)
{
	int	dist_up;
	int	dist_down;

	dist_up = pos;
	dist_down = size - pos;
	if (dist_up <= dist_down)
	{
		while (dist_up > 0)
		{
			ft_ra(a, bench);
			dist_up--;
		}
	}
	else
	{
		while (dist_down > 0)
		{
			ft_rra(a, bench);
			dist_down--;
		}
	}
}

static void	push_bucket_to_b(t_node **a, t_node **b, t_bucket *bucket,
		t_bench *bench)
{
	int	pos;
	int	size;

	pos = find_pos_in_bucket(*a, bucket);
	if (pos == -1)
	{
		bucket->current_count = bucket->target_count;
		return ;
	}
	size = count_stack(a);
	rotate_to_pos(a, pos, size, bench);
	ft_pb(b, a, bench);
	bucket->current_count++;
	if (*b && (*b)->next && (*b)->value < (*b)->next->value)
		ft_rb(b, bench);
}

static void	push_all_buckets(t_node **a, t_node **b, t_chunk *ctx,
		t_bench *bench)
{
	int	active_idx;
	int	total_pushed;

	total_pushed = 0;
	while (total_pushed < ctx->total_size)
	{
		active_idx = find_active_bucket(ctx->buckets, ctx->bucket_count);
		if (active_idx == -1)
			break ;
		push_bucket_to_b(a, b, &ctx->buckets[active_idx], bench);
		total_pushed++;
	}
}

void	sqrt_n_chunk_sort(t_node **a, t_node **b, t_bench *bench)
{
	t_chunk	ctx;
	int		size;
	int		bucket_count;
	int		min_val;
	int		max_val;

	size = count_stack(a);
	bucket_count = 2;
	while (bucket_count * bucket_count < size && bucket_count < size)
		bucket_count++;
	find_min_max(*a, &min_val, &max_val);
	ctx.buckets = malloc(sizeof(t_bucket) * bucket_count);
	if (!ctx.buckets)
		return ;
	ctx.bucket_count = bucket_count;
	ctx.total_size = size;
	init_buckets(ctx.buckets, bucket_count, min_val, max_val);
	count_buckets(*a, ctx.buckets, bucket_count);
	push_all_buckets(a, b, &ctx, bench);
	free(ctx.buckets);
	while (*b)
		push_max_to_a(a, b, bench);
}
