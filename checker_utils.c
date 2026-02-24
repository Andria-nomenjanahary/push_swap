/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:27:32 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/24 15:38:17 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int	count_numbers(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
	}
	return (count);
}

char	*extract_number(char *s, int idx)
{
	int	i;
	int	start;
	int	len;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		start = i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		if (count == idx)
		{
			len = i - start;
			return (ft_substr(s, start, len));
		}
		count++;
	}
	return (NULL);
}

int	user_input(t_node **a, t_node **b, int *eof)
{
	char	*line;
	int		ret;

	ret = read_line(&line);
	if (ret == 0)
	{
		*eof = 1;
		return (0);
	}
	if (ret == -1)
		return (-1);
	move_checker(a, b, line);
	free(line);
	return (1);
}

static int	fill_stack_a(int ac, char **av, t_node **a)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (-1);
		nb = ft_atoi(av[i]);
		add_back(a, new_node(nb));
		i++;
	}
	return (0);
}

int	parse_checker_args(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		input;
	int		eof;

	a = NULL;
	b = NULL;
	if (fill_stack_a(ac, av, &a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (free_stack(&a), -1);
	}
	eof = 0;
	while (!eof)
	{
		input = user_input(&a, &b, &eof);
		if (input == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (free_stack(&a), free_stack(&b), -1);
		}
	}
	stack_in_order(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
