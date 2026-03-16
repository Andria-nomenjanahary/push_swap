/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:54:11 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 10:05:14 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	bench_sa(t_bench *bench)
{
	bench->sa++;
}

void	bench_sb(t_bench *bench)
{
	bench->sb++;
}

void	bench_ss(t_bench *bench)
{
	bench->ss++;
}
