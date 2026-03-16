/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:46:29 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 16:34:00 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H
# include "libft/libft.h"

typedef struct s_node	t_node;

typedef struct s_bench
{
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_bench;

void					init_bench(t_bench *bench);
void					bench_sa(t_bench *bench);
void					bench_sb(t_bench *bench);
void					bench_ss(t_bench *bench);
void					bench_pa(t_bench *bench);
void					bench_pb(t_bench *bench);
void					bench_ra(t_bench *bench);
void					bench_rb(t_bench *bench);
void					bench_rr(t_bench *bench);
void					bench_rra(t_bench *bench);
void					bench_rrb(t_bench *bench);
void					bench_rrr(t_bench *bench);
int						get_total_ops(t_bench *bench);
char					*get_strategy_name(char *flag, float disorder);
float					compute_disorder(t_node **a);
void					exec_algo(char *flag, t_node **a, t_node **b,
							t_bench *bench);
void					ft_adaptive_algo(t_node **stack_a, t_node **stack_b,
							t_bench *bench);

#endif