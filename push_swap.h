/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:07:05 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 17:23:25 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_bench	t_bench;

void	ft_pa_pb(t_node **from, t_node **to);
void	ft_ra_rb(t_node **stack);
void	ft_rra_rrb(t_node **stack);
void	ft_sa_sb(t_node **stack);
void	ft_ra(t_node **a, t_bench *bench);
void	ft_rb(t_node **b, t_bench *bench);
void	ft_rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_rra(t_node **a, t_bench *bench);
void	ft_rrb(t_node **b, t_bench *bench);
void	ft_rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_sa(t_node **a, t_bench *bench);
void	ft_sb(t_node **b, t_bench *bench);
void	ft_ss(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_pb(t_node **a, t_node **b, t_bench *bench);
void	ft_pa(t_node **b, t_node **a, t_bench *bench);
void	ft_simple_algo(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_medium_algo(t_node **a, t_node **b, t_bench *bench);
void	ft_complex_algo(t_node **a, t_node **b, t_bench *bench);
void	ft_adaptive_algo(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	print_stack(t_node *stack);
void	add_back(t_node **stack, t_node *new);
int		find_max(t_node **top);
int		find_min(t_node **top);
int		count_stack(t_node **top);
int		calc_end_idx(int start, int chunk_size, int total_size);
int		is_in_chunk(int value, int *sorted_array, int start_idx, int end_idx);
int		is_number(const char *str);
int		parse_one_number(char **argv, int *i, t_node **stack_a);
float	compute_disorder(t_node **a);
t_node	*new_node(int value);
int		ft_strcmp(const char *s1, const char *s2);
int		get_pos_in_stack(t_node *stack, int value);
int		parse_args(int ac, char **av, int start_idx, t_node **a);
int		is_valid_flag(char *arg);
int		count_total_numbers(int ac, char **av, int start_idx);
int		check_duplicates(t_node *stack);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);
void	exec_algo(char *flag, t_node **a, t_node **b, t_bench *bench);
void	print_error(void);
int		is_valid_number(char *str);
int		partition(int *arr, int low, int high);
void	assign_indices(t_node **stack, int *tmp, int size);
int		*get_sorted_array(t_node *stack, int size);
void	quick_sort(int *arr, int low, int high);
int		parse_str(char *str, t_node **a);
int		parse_args(int ac, char **av, int start_idx, t_node **a);
void	bench_op_a(t_bench *bench, int op_type);
void	bench_op_b(t_bench *bench, int op_type);
void	bench_op_both(t_bench *bench, int op_type);
void	init_bench(t_bench *bench);
int		get_total_ops(t_bench *bench);

#endif
