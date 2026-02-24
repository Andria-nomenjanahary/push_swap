/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:18:58 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/24 08:20:51 by yvoandri         ###   ########.fr       */
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

void	bench_rra(t_bench *bench)
{
	bench->rra++;
}

void	bench_rrb(t_bench *bench)
{
	bench->rrb++;
}
