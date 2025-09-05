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

#include "push_swap.h"
#include <stddef.h>
#include <limits.h>
int get_max_bits(t_stack *a)
{
    int max_value = a->top->value;
    t_node *current = a->top->next;

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
    return max_bit_count;
}
void radix_sort(t_stack *a, t_stack *b)
{
    int max_bit_count;
    int i;
    int j;

    max_bit_count = get_max_bits(a);
    i = 0;
    while (i < max_bit_count)
    {
        j = 0;
        while (j < a->size)
        {
            int value = a->top->value;
            if (((value >> i) & 1) == 0) {
                ra(a);
            } else {
                pb(a, b);
            }
            j++;
        }
        while (b->size > 0) {
            pa(a, b);
        }
        i++;
    }
}
void push(t_stack *stack, int nmbr)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if(!new_node)
    {
        error_exit();
        exit(1);
    }
    new_node->value = nmbr;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}


int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    stack_b.top = NULL;
    stack_a.top = NULL;
    stack_b.size = 0;
    stack_a.size = 0;
    int i = 1;
    if (argc == 1)
        return 0;
    if (handle_errors(argv) != 0)
        return 1;
    while (i < argc)
    {
        int nmbr = ft_atoi(argv[i]);
        push(&stack_a, nmbr);
        i++;
    }
    if (is_sorted(&stack_a))
        return 0;
    radix_sort(&stack_a, &stack_b);

    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}