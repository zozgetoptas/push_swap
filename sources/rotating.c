/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:51 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:52 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void ra(t_stack *stack_a)
{
    if (stack_a == NULL || stack_a->size < 2)
        return;

    t_node *first;
    t_node *last;

    first = stack_a->top;
    stack_a->top = first->next;

    last = first;
    while (last->next != NULL)
        last = last->next;
    first->next = NULL;
    last->next = first;
}
void ra_write(t_stack *stack_a)
{
    ra(stack_a);
    write(1, "ra\n", 3);
}
void rb(t_stack *stack_b)
{
    if (stack_b == NULL || stack_b->size < 2)
        return;

    t_node *first;
    t_node *last;

    first = stack_b->top;
    stack_b->top = first->next;

    last = first;
    while (last->next != NULL)
        last = last->next;
    first->next = NULL;
    last->next = first;
}
void rb_write(t_stack *stack_b)
{
    rb(stack_b);
    write(1, "rb\n", 3);
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
    int rotated = 0;

    if (stack_a && stack_a->size >= 2)
    {
        ra(stack_a);
        rotated = 1;
    }
    if (stack_b && stack_b->size >= 2)
    {
        rb(stack_b);
        rotated = 1;
    }
    if (rotated)
        write(1, "rr\n", 3);
}
