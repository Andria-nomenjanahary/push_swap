/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:30 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/19 13:09:03 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_one_number(char **argv, int *i, t_node **stack_a)
{
	int	num;

	if (!argv[*i] || !is_number(argv[*i]))
		return (1);
	num = ft_atoi(argv[*i]);
	add_back(stack_a, new_node(num));
	*i = *i + 1;
	return (0);
}
