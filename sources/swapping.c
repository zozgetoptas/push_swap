/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:56 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:57 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void sa(t_stack *stack_a)
{
	t_node *first;
	t_node *second;
	if (stack_a == NULL || stack_a->size < 2)
		return;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;

}
void sa_write(t_stack *stack_a)
{
	sa(stack_a);
	write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
	t_node *first;
	t_node *second;
	if (stack_b == NULL || stack_b->size < 2)
		return;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;

	write(1, "sb\n", 3);
}
void sb_write(t_stack *stack_b)
{
	sb(stack_b);
	write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	int swapped = 0;
	
	if (stack_a && stack_a->size >= 2)
	{
		sa(stack_a);
		swapped = 1;
	}
	if (stack_b && stack_b->size >= 2)
	{
		sb(stack_b);
		swapped = 1;
	}
	if (swapped)
		write(1, "ss\n", 3);
}
