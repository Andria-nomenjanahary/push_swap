/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:34:26 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/23 14:41:52 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
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
		tmp[i++] = curr->value;
		curr = curr->next;
	}
	quick_sort(tmp, 0, size - 1);
	return (tmp);
}
