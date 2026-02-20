/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:54:32 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/20 17:10:47 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// Helper to print the current state of the stack
void print_stack_status(t_node *a, t_node *b)
{
    printf("A: ");
    while (a) {
        printf("%d ", a->value);
        a = a->next;
    }
    printf("\nB: ");
    while (b) {
        printf("%d ", b->value);
        b = b->next;
    }
    printf("\n----------------\n");
}

int main(void)
{
    t_node *a = NULL;
    t_node *b = NULL;

    // Manually add test values (e.g., 35 78 99 11 25 12)
    // In a real test, use your stack_add_back functions here
    // For this example, assume a linked list is constructed:
	a = new_node(35);
    a->next = new_node(78);
    a->next->next = new_node(99);
    a->next->next->next = new_node(11);
    a->next->next->next->next = new_node(25);
    a->next->next->next->next->next = new_node(12);

    printf("Initial Stack:\n");
    print_stack_status(a, b);

    ft_complex_algo(&a, &b); // Or ft_complex_algo(&a, &b)

    printf("Sorted Stack:\n");
    print_stack_status(a, b);

    return (0);
}
