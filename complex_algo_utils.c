/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainadan <ainradan@student.42antananariv    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:05:33 by ainadan           #+#    #+#             */
/*   Updated: 2026/03/05 14:05:40 by ainadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_algo.h"

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		j++;
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	p;

	if (low < high)
	{
		p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}

void	assign_indices(t_node **stack, int *tmp, int size)
{
	t_node	*curr;
	int		i;

	curr = *stack;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (curr->value == tmp[i])
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

int	*get_sorted_array(t_node *stack, int size)
{
	int		*tmp;
	int		i;
	t_node	*curr;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (NULL);
	curr = stack;
	i = 0;
	while (i < size)
	{
		tmp[i] = curr->value;
		curr = curr->next;
		i++;
	}
	quick_sort(tmp, 0, size - 1);
	return (tmp);
}

int	get_median_value(t_node *stack, int size)
{
	int	*tmp;
	int	median;

	tmp = get_sorted_array(stack, size);
	if (!tmp)
		return (0);
	median = tmp[size / 2];
	free(tmp);
	return (median);
}
