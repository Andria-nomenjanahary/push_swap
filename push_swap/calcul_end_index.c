/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_end_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:55 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/17 13:14:54 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc_end_idx(int start, int chunk_size, int total_size)
{
	int	end;

	end = start + chunk_size - 1;
	if (end >= total_size)
		end = total_size - 1;
	return (end);
}
