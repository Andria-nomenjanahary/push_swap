/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:22:38 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/07 08:24:51 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_bench	t_bench;

typedef struct s_node
{
	int					value;
	int					index;
	struct s_node		*next;
}						t_node;

int						is_bench_flag(char *arg);
void					process_option(char *arg, int *bench_mode, char **flag, int *count_only);
void					scan_options(int ac, char **av, int *bench_mode,
							char **flag, int *count_only);
int						find_first_number_index(int ac, char **av);
int						has_options_after_numbers(int ac, char **av,
							int start_idx);
int						validate_options(int ac, char **av);
int						init_options(int ac, char **av, int *bench_mode,
							char **flag, int *count_only);
int						is_option_arg(char *arg);
int						count_numbers_in_arg(char *arg);
int						count_total_numbers_skip_options(int ac, char **av,
							int start_idx);
int						parse_args_skip_options(int ac, char **av,
							int start_idx, t_node **a);
int						parse_args(int ac, char **av, int start_idx,
							t_node **a);
int						parse_str(char *str, t_node **a);
int						count_in_str(char *str);
int						count_total_numbers(int ac, char **av, int start_idx);
float					compute_disorder(t_node **a);
void					exec_algo(char *flag, t_node **a, t_node **b,
							t_bench *bench);
void					run_benchmark(t_node **a, t_node **b, char *flag);
void					ft_simple_algo(t_node **stack_a, t_node **stack_b,
							t_bench *bench);
void					ft_adaptive_algo(t_node **stack_a, t_node **stack_b,
							t_bench *bench);
int						count_stack(t_node **stack);
int						find_min(t_node **stack);
int						find_max(t_node **top);
int						get_pos_in_stack(t_node *stack, int value);
void					print_error(void);
void					free_stack(t_node **stack);
int						is_valid_flag(char *arg);
t_node					*new_node(int value);
void					add_back(t_node **stack, t_node *new);
int						is_valid_number(char *str);
void					ft_medium_algo(t_node **a, t_node **b, t_bench *bench);
int						is_number(const char *str);
int						is_algo_flag(char *arg);
int						has_options_between_numbers(int ac, char **av);

#endif
