/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:54:48 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 09:55:30 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	bench_ra(t_bench *bench)
{
	bench->ra++;
}

void	bench_rb(t_bench *bench)
{
	bench->rb++;
}

void	bench_rr(t_bench *bench)
{
	bench->rr++;
}
