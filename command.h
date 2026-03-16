/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:14:36 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 12:34:06 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "push_swap.h"

void	ft_pb(t_node **b, t_node **a, t_bench *bench);
void	ft_pa(t_node **a, t_node **b, t_bench *bench);
void	ft_rb(t_node **b, t_bench *bench);
void	ft_ra(t_node **a, t_bench *bench);
void	ft_rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_ss(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_rra(t_node **a, t_bench *bench);
void	ft_rrb(t_node **b, t_bench *bench);
void	ft_rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ft_sa(t_node **a, t_bench *bench);
void	ft_sb(t_node **b, t_bench *bench);

#endif