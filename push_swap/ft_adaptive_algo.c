/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:05:25 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 11:05:28 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

void	ft_adaptive_algo(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	float	disorder;

	disorder = compute_disorder(stack_a);
	if (disorder < 0.2)
		ft_simple_algo(stack_a, stack_b, bench);
	else if (disorder >= 0.2 && disorder < 0.5)
		ft_medium_algo(stack_a, stack_b, bench);
	else
		ft_complex_algo(stack_a, stack_b, bench);
}
