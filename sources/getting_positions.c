/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:32 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:33 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_position(t_stack *stack, int value)
{
    int position = 0;
    t_node *current;
    if(!stack || !stack->top)
        return (-1);
    current = stack->top;
    while(current)
    {
        if (current->value == value)
            return position;
        current = current->next;
        position++;
    }
    return (-1);
}
int get_min_position(t_stack *stack)
{
    int min_value;
    if(!stack || !stack->top)
        return (-1);
    min_value = get_min_value(stack);
    return(get_position(stack, min_value));
}
int get_max_position(t_stack *stack)
{
    int max_value;
    if(!stack || !stack->top)
        return (-1);
    max_value = get_max_value(stack);
    return(get_position(stack, max_value));
}
void normalize_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;
    
    current = stack->top;
    while (current)
    {
        int rank = 0;
        temp = stack->top;
        while (temp)
        {
            if (current->value > temp->value)
            {
                rank++;
            }
            temp = temp->next;
        }
        current->value = rank; // Değeri yeni sıralı pozisyonuyla değiştir
        current = current->next;
    }
}