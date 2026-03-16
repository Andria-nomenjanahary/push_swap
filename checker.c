/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:17:58 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/06 10:18:26 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "checker.h"
#include "hashset.h"
#include "push_swap.h"

static int	process_arg(char *arg, t_node **a)
{
	if (is_number(arg))
	{
		if (!is_valid_number(arg))
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		add_back(a, new_node(ft_atoi(arg)));
		return (0);
	}
	if (fill_stack_string(arg, a) == -1)
		return (-1);
	return (0);
}

static int	fill_stack_args(int ac, char **av, t_node **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (process_arg(av[i], a) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (fill_stack_args(ac, av, &a) == -1)
		return (free_stack(&a), 1);
	if (check_duplicates(a))
	{
		ft_putstr_fd("Error\n", 2);
		return (free_stack(&a), 1);
	}
	if (read_commands(&a, &b) == -1)
	{
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	stack_in_order(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
