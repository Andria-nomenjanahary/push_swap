/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:31:32 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/06 15:54:04 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "bench.h"

static void	ft_ra_rb(t_node **stack)
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

void	ft_rb(t_node **b, t_bench *bench)
{
	ft_ra_rb(b);
	write(1, "rb\n", 3);
	if (bench)
		bench_rb(bench);
}

void	ft_ra(t_node **a, t_bench *bench)
{
	ft_ra_rb(a);
	write(1, "ra\n", 3);
	if (bench)
		bench_ra(bench);
}

void	ft_rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	ft_ra_rb(stack_a);
	ft_ra_rb(stack_b);
	write(1, "rr\n", 3);
	if (bench)
		bench_rr(bench);
}
