/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:51:11 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/02 16:00:25 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	fill_stack_string(char *str, t_node **a)
{
	int		i;
	int		count;
	char	*num;

	count = count_numbers(str);
	i = 0;
	while (i < count)
	{
		num = extract_number(str, i);
		if (!num || !is_number(num))
		{
			ft_putstr_fd("Error\n", 2);
			free(num);
			return (-1);
		}
		add_back(a, new_node(ft_atoi(num)));
		free(num);
		i++;
	}
	return (0);
}

int	read_commands(t_node **a, t_node **b)
{
	int	input;
	int	eof;

	eof = 0;
	while (!eof)
	{
		input = user_input(a, b, &eof);
		if (input == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	parse_string(char *str)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (fill_stack_string(str, &a) == -1)
		return (free_stack(&a), -1);
	if (read_commands(&a, &b) == -1)
		return (free_stack(&a), free_stack(&b), -1);
	stack_in_order(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
