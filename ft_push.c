/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:59:45 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 08:45:45 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_pb(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	ft_pb(t_node **b, t_node **a)
{
	ft_pa_pb(b, a);
	write(1, "pb\n", 3);
}

void	ft_pa(t_node **a, t_node **b)
{
	ft_pa_pb(a, b);
	write(1, "pa\n", 3);
}
