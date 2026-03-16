/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:45:24 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/06 15:54:09 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "bench.h"

static void	ft_rra_rrb(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	prev->next = NULL;
}

void	ft_rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	ft_rra_rrb(stack_a);
	ft_rra_rrb(stack_b);
	write(1, "rrr\n", 4);
	if (bench)
		bench_rrr(bench);
}

void	ft_rrb(t_node **b, t_bench *bench)
{
	ft_rra_rrb(b);
	write(1, "rrb\n", 4);
	if (bench)
		bench_rrb(bench);
}

void	ft_rra(t_node **a, t_bench *bench)
{
	ft_rra_rrb(a);
	write(1, "rra\n", 4);
	if (bench)
		bench_rra(bench);
}
