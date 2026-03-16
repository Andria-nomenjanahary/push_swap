/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:16:47 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/06 15:54:18 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "bench.h"

static void	ft_pa_pb(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	ft_pb(t_node **b, t_node **a, t_bench *bench)
{
	ft_pa_pb(b, a);
	write(1, "pb\n", 3);
	if (bench)
		bench_pb(bench);
}

void	ft_pa(t_node **a, t_node **b, t_bench *bench)
{
	ft_pa_pb(a, b);
	write(1, "pa\n", 3);
	if (bench)
		bench_pa(bench);
}
