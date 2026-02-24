/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:02:55 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/21 13:02:57 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashset.h"

unsigned int	hash_function(int value)
{
	unsigned int	hash;

	hash = (unsigned int)value;
	if (value < 0)
		hash = (unsigned int)(-value) + HASHSET_SIZE / 2;
	return (hash % HASHSET_SIZE);
}

t_hashset	*hashset_create(void)
{
	t_hashset	*set;
	int			i;

	set = (t_hashset *)malloc(sizeof(t_hashset));
	if (!set)
		return (NULL);
	i = 0;
	while (i < HASHSET_SIZE)
	{
		set->buckets[i] = NULL;
		i++;
	}
	return (set);
}

void	hashset_destroy(t_hashset *set)
{
	t_hash_node	*current;
	t_hash_node	*tmp;
	int			i;

	if (!set)
		return ;
	i = 0;
	while (i < HASHSET_SIZE)
	{
		current = set->buckets[i];
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		i++;
	}
	free(set);
}

int	hashset_contains(t_hashset *set, int value)
{
	unsigned int	index;
	t_hash_node		*current;

	if (!set)
		return (0);
	index = hash_function(value);
	current = set->buckets[index];
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	hashset_insert(t_hashset *set, int value)
{
	unsigned int	index;
	t_hash_node		*new_node;

	if (!set)
		return (0);
	if (hashset_contains(set, value))
		return (0);
	index = hash_function(value);
	new_node = (t_hash_node *)malloc(sizeof(t_hash_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = set->buckets[index];
	set->buckets[index] = new_node;
	return (1);
}
