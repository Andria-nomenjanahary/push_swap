/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_in_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:05:11 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/24 15:03:46 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_in_order(t_node **a, t_node **b)
{
	if (*b == NULL && is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_putstr_fd("KO\n", 2);
}
