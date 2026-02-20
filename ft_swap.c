/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:04:13 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 08:45:05 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_node **stack)
{
	int	temp;

	if (!stack || !(*stack))
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_sa_sb(stack_a);
	ft_sa_sb(stack_b);
}

void	ft_sa(t_node **a)
{
	ft_sa_sb(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_node **b)
{
	ft_sa_sb(b);
	write(1, "sb\n", 3);
}
