#include "push_swap.h"
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

void ss(t_stack *stack_a, t_stack *stack_b)
{
    t_node *first_a;
    t_node *second_a;
    if (stack_a == NULL || stack_a->size < 2)
        return;
    first_a = stack_a->top;
    second_a = first_a->next;
    first_a->next = second_a->next;
    second_a->next = first_a;
    stack_a->top = second_a;

    t_node *first_b;
    t_node *second_b;
    if (stack_b == NULL || stack_b->size < 2)
        return;
    first_b = stack_b->top;
    second_b = first_b->next;
    first_b->next = second_b->next;
    second_b->next = first_b;
    stack_b->top = second_b;

    write(1, "ss\n", 3);
}
