/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_reverse_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:55:33 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 11:46:48 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	bench_rra(t_bench *bench)
{
	bench->rra++;
}

void	bench_rrb(t_bench *bench)
{
	bench->rrb++;
}

void	bench_rrr(t_bench *bench)
{
	bench->rrr++;
}
