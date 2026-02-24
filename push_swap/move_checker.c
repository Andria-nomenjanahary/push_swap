/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:50:08 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 17:01:41 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	move_checker(t_node **a, t_node **b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb") == 00)
		sb(b);
	else if (ft_strcmp(command, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(command, "pb") == 0)
		pb(b, a);
	else if (ft_strcmp(command, "ra") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb") == 0)
		rb(b);
	else if (ft_strcmp(command, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b);
	else
		ft_putstr_fd("Error\n", 2);
}
