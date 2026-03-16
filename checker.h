/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:51:08 by ainradan          #+#    #+#             */
/*   Updated: 2026/03/05 09:39:50 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include "push_swap.h"

int		count_numbers(char *s);
int		parse_checker_args(int ac, char **av);
char	*extract_number(char *s, int idx);
int		parse_string(char *str);
int		user_input(t_node **a, t_node **b, int *eof);
int		move_checker(t_node **a, t_node **b, char *command);
void	ss(t_node **stack_a, t_node **stack_b);
void	sa(t_node **a);
void	sb(t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rb(t_node **b);
void	ra(t_node **a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rrb(t_node **b);
void	rra(t_node **a);
void	stack_in_order(t_node **a, t_node **b);
int		read_line(char **line);
void	free_stack(t_node **stack);
void	print_error(void);
int		fill_stack_string(char *str, t_node **a);
int		read_commands(t_node **a, t_node **b);
int		is_algo_flag(char *arg);
int		is_number_string(char *arg);
int		has_options_between_numbers(int ac, char **av);

#endif
