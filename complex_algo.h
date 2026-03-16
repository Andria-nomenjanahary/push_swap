/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:04:47 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/06 09:56:15 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_ALGO_H
# define COMPLEX_ALGO_H

# include "command.h"
# include "push_swap.h"

int		partition(int *arr, int low, int high);
int		*get_sorted_array(t_node *stack, int size);
int		get_median_value(t_node *stack, int size);
void	ft_complex_algo(t_node **a, t_node **b, t_bench *bench);
void	assign_indices(t_node **stack, int *tmp, int size);
void	radix_lsd_sort(t_node **a, t_node **b, int size, t_bench *bench);
void	sort_two_complex(t_node **a, t_bench *bench);
void	sort_three_complex(t_node **a, t_bench *bench);
void	sort_four_complex(t_node **a, t_node **b, t_bench *bench);
void	sort_five_complex(t_node **a, t_node **b, t_bench *bench);

#endif
