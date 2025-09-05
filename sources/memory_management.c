/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:38 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:39 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;

    if(!stack || !stack->top)
        return;
    current = stack->top;
    while(current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    stack->top = NULL;
    stack->size = 0;
}

int pop(t_stack *stack)
{
    t_node *temp;
    int value;
    
    if (!stack || !stack->top)
        return (0);
    
    temp = stack->top;
    value = temp->value;
    stack->top = stack->top->next;
    stack->size--;
    free(temp);
    return (value);
}

void push(t_stack *stack, int value)
{
    t_node *new_node;
    
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        error_exit();
    
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}
int get_optimal_rotate_direction(t_stack *stack, int target_value)
{
    int pos;
    int size;
    
    pos = get_position(stack, target_value);
    size = stack->size; 
    if (pos == -1)
        return (0);
    if (pos <= size / 2)
        return (1);
    else
        return (-1);
}
