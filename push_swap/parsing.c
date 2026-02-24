/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:26:32 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 16:16:23 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	extract_number(char *str, int *i, char **start, int *len)
{
	while (str[*i] == ' ')
		(*i)++;
	if (!str[*i])
		return (0);
	*start = &str[*i];
	*len = 0;
	if (str[*i] == '-')
	{
		(*len)++;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*len)++;
		(*i)++;
	}
	return (*len > 0);
}

static int	process_number(char *num_str, t_node **a)
{
	int	value;

	if (!is_valid_number(num_str))
		return (free(num_str), 0);
	value = ft_atoi(num_str);
	free(num_str);
	add_back(a, new_node(value));
	return (1);
}

int	parse_str(char *str, t_node **a)
{
	int		i;
	char	*start;
	char	*num_str;
	int		len;

	i = 0;
	while (str[i])
	{
		if (!extract_number(str, &i, &start, &len))
		{
			if (str[i] && str[i] != ' ')
				return (0);
			break ;
		}
		num_str = malloc(len + 1);
		if (!num_str)
			return (0);
		ft_strlcpy(num_str, start, len + 1);
		if (!process_number(num_str, a))
			return (0);
	}
	return (1);
}

static int	count_in_str(char *str)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == ' ')
			j++;
		if (ft_isdigit(str[j]) || (str[j] == '-' && ft_isdigit(str[j + 1])))
		{
			count++;
			if (str[j] == '-')
				j++;
			while (ft_isdigit(str[j]))
				j++;
		}
		else if (str[j])
			return (-1);
	}
	return (count);
}

int	count_total_numbers(int ac, char **av, int start_idx)
{
	int	total_count;
	int	current_count;
	int	i;

	total_count = 0;
	i = start_idx;
	while (i < ac)
	{
		current_count = count_in_str(av[i]);
		if (current_count == -1)
			return (-1);
		total_count += current_count;
		i++;
	}
	return (total_count);
}
