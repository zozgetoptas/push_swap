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