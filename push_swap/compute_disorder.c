/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:40:29 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/18 16:13:04 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_node **a)
{
	t_node	*cur_i;
	t_node	*cur_j;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	cur_i = *a;
	while (cur_i)
	{
		cur_j = cur_i->next;
		while (cur_j)
		{
			total_pairs++;
			if (cur_i->value > cur_j->value)
				mistakes++;
			cur_j = cur_j->next;
		}
		cur_i = cur_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / (float)total_pairs);
}
