/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainradan <ainradan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:23:56 by ainradan          #+#    #+#             */
/*   Updated: 2026/02/20 16:35:59 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void quick_sort(int *arr, int low, int high) {
  int pivot;
  int i;
  int j;
  int temp;

  if (low < high) {
    pivot = arr[high];
    i = low - 1;
    j = low;
    while (j < high) {
      if (arr[j] < pivot) {
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
    quick_sort(arr, low, i);
    quick_sort(arr, i + 2, high);
  }
}

static void normalize_to_indices(t_node **stack, int size) {
  int *tmp;
  int i;
  t_node *curr;

  tmp = malloc(sizeof(int) * size);
  if (!tmp)
    return;
  curr = *stack;
  i = 0;
  while (i < size) {
    tmp[i++] = curr->value;
    curr = curr->next;
  }
  quick_sort(tmp, 0, size - 1);
  curr = *stack;
  while (curr) {
    i = 0;
    while (i < size) {
      if (curr->value == tmp[i]) {
        curr->index = i;
        break;
      }
      i++;
    }
    curr = curr->next;
  }
  free(tmp);
}

static int get_max_bits(int size) {
  int bits;

  bits = 0;
  while (((size - 1) >> bits) != 0)
    bits++;
  return (bits);
}

static void process_bit(t_node **a, t_node **b, int bit, int size) {
  int i;

  i = 0;
  while (i < size) {
    if ((((*a)->index >> bit) & 1) == 1)
      ft_ra(a);
    else
      ft_pb(b, a);
    i++;
  }
  while (*b)
    ft_pa(a, b);
}

void ft_complex_algo(t_node **a, t_node **b) {
  int bit;
  int max_bits;
  int size;

  if (!a || !*a)
    return;
  size = count_stack(a);
  if (size <= 1)
    return;
  normalize_to_indices(a, size);
  max_bits = get_max_bits(size);
  bit = 0;
  while (bit < max_bits) {
    process_bit(a, b, bit, size);
    bit++;
  }
}
