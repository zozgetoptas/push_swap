/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:42 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:42 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stddef.h>
#include <limits.h>
int get_max_bits(t_stack *a)
{
    int max_value = a->top->value;
    t_node *current = a->top;

    if (!a || !a->top)
        return 0;

    while(current)
    {
        if (current->value > max_value)
            max_value = current->value;
        current = current->next;
    }
    int max_bit_count = 0;
    if (max_value == 0)
        return 1;
    while ((max_value >> max_bit_count) != 0)
        max_bit_count++;
    return (max_bit_count);
}
void radix_sort(t_stack *a, t_stack *b)
{
    int max_bit_count;
    int i;
    int j;
    int a_stack_size;

    max_bit_count = get_max_bits(a);
    i = 0;
    while (i < max_bit_count)
    {
        a_stack_size = a->size;
        j = 0;
        while (j < a_stack_size)
        {
            int value = a->top->value;
            if (((value >> i) & 1) == 0)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (b->size > 0) {
            pa(a, b);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc == 1)
        return 0;
    handle_errors(argv);
    stack_a = parse_arguments(argv);
    stack_b = NULL;
    if (is_sorted(stack_a))
    {
        free_stack(stack_a);
        return 0;
    }
    if (stack_a->size <= 5)
	 	sort_small(&stack_a, &stack_b);
	else
		sort_large(&stack_a, &stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}
