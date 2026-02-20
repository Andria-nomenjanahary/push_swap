/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:45:41 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 13:47:35 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sort_array(int size, t_node *top)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	cur = top;
	i = 0;
	while (i < size && cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	sort_array(arr, size);
	return (arr);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	max_val;
	int	size;
	int	pos;

	while (*b)
	{
		max_val = find_max(b);
		size = count_stack(b);
		pos = get_pos_in_stack(*b, max_val);
		if (pos <= size / 2)
		{
			while ((*b)->value != max_val)
				ft_rb(b);
		}
		else
		{
			while ((*b)->value != max_val)
				ft_rrb(b);
		}
		ft_pa(a, b);
	}
}

void	ft_medium_algo(t_node **a, t_node **b)
{
	int	*arr;
	int	size;
	int	i;
	int	chunk;

	size = count_stack(a);
	arr = create_sort_array(size, *a);
	if (!arr)
		return ;
	i = 0;
	chunk = 15;
	while (*a)
	{
		if ((*a)->value <= arr[i])
		{
			ft_pb(b, a);
			ft_rb(b);
			i++;
		}
		else if (i + chunk < size && (*a)->value <= arr[i + chunk])
		{
			ft_pb(b, a);
			i++;
		}
		else
			ft_ra(a);
	}
	push_back_to_a(a, b);
	free(arr);
}
