/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:48 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:49 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void rra(t_stack *stack_a)
{
    if (stack_a == NULL || stack_a->size < 2)
        return;

    t_node *first;
    t_node *last;
    t_node *just_before_the_last;

    first = stack_a->top;
    just_before_the_last = NULL;
    last = first;
    while (last->next != NULL)
    {
        just_before_the_last = last;
        last = last->next;
    }
    if (just_before_the_last != NULL)
        just_before_the_last->next = NULL;
    last->next = first;
    stack_a->top = last;
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b)
{
    if (stack_b == NULL || stack_b->size < 2)
        return;

    t_node *first;
    t_node *last;
    t_node *just_before_the_last;

    first = stack_b->top;
    just_before_the_last = NULL;
    last = first;
    while (last->next != NULL)
    {
        just_before_the_last = last;
        last = last->next;
    }
    if (just_before_the_last != NULL)
        just_before_the_last->next = NULL;
    last->next = first;
    stack_b->top = last;
    write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    int rotated_a = 0;
    int rotated_b = 0;
    
    if (stack_a != NULL && stack_a->size >= 2)
    {
        t_node *first_a = stack_a->top;
        t_node *last_a = first_a;
        t_node *just_before_the_last_a = NULL;
        while (last_a->next != NULL)
        {
            just_before_the_last_a = last_a;
            last_a = last_a->next;
        }
        if (just_before_the_last_a != NULL)
            just_before_the_last_a->next = NULL;
        last_a->next = first_a;
        stack_a->top = last_a;
        rotated_a = 1;
    }
    
    if (stack_b != NULL && stack_b->size >= 2)
    {
        t_node *first_b = stack_b->top;
        t_node *last_b = first_b;
        t_node *just_before_the_last_b = NULL;
        while (last_b->next != NULL)
        {
            just_before_the_last_b = last_b;
            last_b = last_b->next;
        }
        if (just_before_the_last_b != NULL)
            just_before_the_last_b->next = NULL;
        last_b->next = first_b;
        stack_b->top = last_b;
        rotated_b = 1;
    }

    if (rotated_a || rotated_b)
        write(1, "rrr\n", 4);
}
