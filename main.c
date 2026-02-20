/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:24 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 11:07:28 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0 || ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0 || ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

static void	exec_algo(char *flag, t_node **a, t_node **b)
{
	if (ft_strcmp(flag, "--simple") == 0)
		ft_simple_algo(a, b);
	else if (ft_strcmp(flag, "--medium") == 0)
		ft_medium_algo(a, b);
	else if (ft_strcmp(flag, "--complex") == 0)
		ft_complex_algo(a, b);
	else
		ft_adaptive_algo(a, b);
}

static void	parse_str(char *str, t_node **a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			add_back(a, new_node(ft_atoi(&str[i])));
			if (str[i] == '-')
				i++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;
	char	*flag;

	a = NULL;
	b = NULL;
	flag = NULL;
	if (ac > 1 && is_valid_flag(av[1]))
		flag = av[1];
	i = 1;
	if (flag)
		i = 2;
	while (i < ac)
	{
		parse_str(av[i], &a);
		i++;
	}
	if (flag)
		exec_algo(flag, &a, &b);
	else
		ft_adaptive_algo(&a, &b);
	return (0);
}
