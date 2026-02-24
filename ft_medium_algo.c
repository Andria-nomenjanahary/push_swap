/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:05:38 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/23 15:18:59 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bench.h"

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

static void	push_back_to_a(t_node **a, t_node **b, t_bench *bench)
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
				ft_rb(b, bench);
		}
		else
		{
			while ((*b)->value != max_val)
				ft_rrb(b, bench);
		}
		ft_pa(a, b, bench);
	}
}

static void	push_to_b(t_node **a, t_node **b, int *arr, t_bench *bench)
{
	int	i;
	int	chunk;
	int	size;

	i = 0;
	chunk = 15;
	size = count_stack(a);
	while (*a)
	{
		if ((*a)->value <= arr[i])
		{
			ft_pb(b, a, bench);
			ft_rb(b, bench);
			i++;
		}
		else if (i + chunk < size && (*a)->value <= arr[i + chunk])
		{
			ft_pb(b, a, bench);
			i++;
		}
		else
			ft_ra(a, bench);
	}
}

void	ft_medium_algo(t_node **a, t_node **b, t_bench *bench)
{
	int	*arr;
	int	size;

	size = count_stack(a);
	arr = create_sort_array(size, *a);
	if (!arr)
		return ;
	push_to_b(a, b, arr, bench);
	push_back_to_a(a, b, bench);
	free(arr);
}
