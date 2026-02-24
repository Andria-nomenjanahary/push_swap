/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:27:56 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/24 15:04:45 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ra_rb(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
}

void	rb(t_node **b)
{
	ra_rb(b);
}

void	ra(t_node **a)
{
	ra_rb(a);
}
