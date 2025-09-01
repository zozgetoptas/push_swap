#include "push_swap.h"

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
    get_position(stack, min_value);
}
int get_max_position(t_stack *stack)
{
    int max_value;
    if(!stack || !stack->top)
        return (-1);
    max_value = get_max_value(stack);
    get_position(stack, max_value);
}