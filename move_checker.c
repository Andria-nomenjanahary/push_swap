/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:50:08 by ainradan          #+#    #+#             */
/*   Updated: 2026/03/05 10:03:48 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_swap_command(t_node **a, t_node **b, char *command)
{
	if (ft_strncmp(command, "sa", ft_strlen(command)) == 0)
	{
		sa(a);
		return (1);
	}
	if (ft_strncmp(command, "sb", ft_strlen(command)) == 0)
	{
		sb(b);
		return (1);
	}
	if (ft_strncmp(command, "ss", ft_strlen(command)) == 0)
	{
		ss(a, b);
		return (1);
	}
	else
		return (0);
}

static int	is_push_command(t_node **a, t_node **b, char *command)
{
	if (ft_strncmp(command, "pa", ft_strlen(command)) == 0)
	{
		pa(a, b);
		return (1);
	}
	else if (ft_strncmp(command, "pb", ft_strlen(command)) == 0)
	{
		pb(b, a);
		return (1);
	}
	else
		return (0);
}

static int	is_rotation_move(t_node **a, t_node **b, char *command)
{
	if (ft_strncmp(command, "ra", ft_strlen(command)) == 0)
	{
		ra(a);
		return (1);
	}
	else if (ft_strncmp(command, "rb", ft_strlen(command)) == 0)
	{
		rb(b);
		return (1);
	}
	else if (ft_strncmp(command, "rr", ft_strlen(command)) == 0)
	{
		rr(a, b);
		return (1);
	}
	else
		return (0);
}

static void	command_move(t_node **a, t_node **b, char *command, int *error)
{
	*error = 0;
	if (is_swap_command(a, b, command))
		*error = 0;
	else if (is_push_command(a, b, command))
		*error = 0;
	else if (is_rotation_move(a, b, command))
		*error = 0;
	else if (ft_strncmp(command, "rra", ft_strlen(command)) == 0)
		rra(a);
	else if (ft_strncmp(command, "rrb", ft_strlen(command)) == 0)
		rrb(b);
	else if (ft_strncmp(command, "rrr", ft_strlen(command)) == 0)
		rrr(a, b);
	else
		*error = 1;
}

int	move_checker(t_node **a, t_node **b, char *command)
{
	int	error;

	command_move(a, b, command, &error);
	if (error)
		return (-1);
	return (0);
}
