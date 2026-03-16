/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:57:42 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/04 12:04:27 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

int	get_total_ops(t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss;
	total += bench->pa + bench->pb;
	total += bench->ra + bench->rb + bench->rr;
	total += bench->rra + bench->rrb + bench->rrr;
	return (total);
}

char	*get_strategy_name(char *flag, float disorder)
{
	if (flag)
	{
		if (!ft_strncmp(flag, "--simple", ft_strlen(flag)))
			return ("Simple / O(n²)");
		if (!ft_strncmp(flag, "--medium", ft_strlen(flag)))
			return ("Medium / O(n√n)");
		if (!ft_strncmp(flag, "--complex", ft_strlen(flag)))
			return ("Complex / O(n log n)");
	}
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}
