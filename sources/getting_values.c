/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:36 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:37 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_min_value(t_stack *stack)
{
    t_node *current;
    int min;

    if(!stack || !stack->top)
        return 0;
    min = stack->top->value;
    current = stack->top->next;
    while(current)
    {
        if(current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

int get_max_value(t_stack *stack)
{
    t_node *current;
    int max;

    if(!stack || !stack->top)
        return 0;
    max = stack->top->value;
    current = stack->top->next;
    while(current)
    {
        if(current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}
int get_value(t_stack *stack, int position)
{
    t_node *current;
    int i = 0;
    if(!stack || !stack->top || position < 0 || position >= stack->size)
        return (0);
    current = stack->top;
    while(i < position)
    {
        i++;
        current = current->next;
    }
    return (current->value);
}

