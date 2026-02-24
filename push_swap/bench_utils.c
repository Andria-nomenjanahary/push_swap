/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:01:57 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/23 17:18:06 by yvoandri         ###   ########.fr       */
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

void	bench_pa(t_bench *bench)
{
	bench->pa++;
}

void	bench_pb(t_bench *bench)
{
	bench->pb++;
}
