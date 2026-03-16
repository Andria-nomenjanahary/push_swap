/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:31:14 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 11:12:55 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_ALGO_H
# define MEDIUM_ALGO_H
# include "push_swap.h"

typedef struct s_bucket
{
	int			min_val;
	int			max_val;
	int			target_count;
	int			current_count;
}				t_bucket;

typedef struct s_chunk
{
	t_bucket	*buckets;
	int			bucket_count;
	int			total_size;
}				t_chunk;

int				find_active_bucket(t_bucket *buckets, int bucket_count);
void			find_min_max(t_node *stack, int *min, int *max);
void			sort_two(t_node **a, t_bench *bench);
void			sort_three(t_node **a, t_bench *bench);
void			sort_four(t_node **a, t_node **b, t_bench *bench);
void			sort_five(t_node **a, t_node **b, t_bench *bench);
void			ft_medium_algo(t_node **a, t_node **b, t_bench *bench);
void			sqrt_n_chunk_sort(t_node **a, t_node **b, t_bench *bench);
void			count_buckets(t_node *stack, t_bucket *buckets,
					int bucket_count);
void			init_buckets(t_bucket *buckets, int bucket_count, int min_val,
					int max_val);
void			push_max_to_a(t_node **a, t_node **b, t_bench *bench);

#endif