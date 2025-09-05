/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checkings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:53 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:54 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top || stack->size <= 1)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int is_reverse_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top || stack->size <= 1)
        return (1);
    current = stack->top;
    while(current->next)
    {
        if (current->value < current->next->value)
            return (0);
        current = current->next;
    }
    return 1;
}