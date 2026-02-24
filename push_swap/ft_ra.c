/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:05:49 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 11:13:29 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

void	ft_ra(t_node **a, t_bench *bench)
{
	ft_ra_rb(a);
	write(1, "ra\n", 3);
	if (bench)
		bench_ra(bench);
}
