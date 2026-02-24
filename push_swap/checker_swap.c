/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:17:27 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 17:23:25 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	sa_sb(t_node **stack)
{
	int	temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa_sb(stack_a);
	sa_sb(stack_b);
}

void	sa(t_node **a)
{
	sa_sb(a);
}

void	sb(t_node **b)
{
	sa_sb(b);
}
