/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:58:22 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/21 13:45:49 by ainradan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHSET_H
# define HASHSET_H
# include "push_swap.h"

# define HASHSET_SIZE 1024

typedef struct s_hash_node
{
	int					value;
	struct s_hash_node	*next;
}						t_hash_node;

typedef struct s_hashset
{
	t_hash_node			*buckets[HASHSET_SIZE];
}						t_hashset;

t_hashset				*hashset_create(void);
void					hashset_destroy(t_hashset *set);
int						hashset_insert(t_hashset *set, int value);
int						hashset_contains(t_hashset *set, int value);
unsigned int			hash_function(int value);

#endif