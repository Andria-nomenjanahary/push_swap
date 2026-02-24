/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:12:38 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/23 16:16:46 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int ac, char **av, int start_idx, t_node **a)
{
	int	i;

	i = start_idx;
	while (i < ac)
	{
		if (!parse_str(av[i], a))
			return (0);
		i++;
	}
	return (1);
}
