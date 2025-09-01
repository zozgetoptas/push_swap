#include "push_swap.h"
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
    write(1, "rb\n", 3);
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *first_a;
    t_node *last_a;
    t_node *first_b;
    t_node *last_b;

    if (stack_a != NULL && stack_a->size >= 2)
    {
        first_a = stack_a->top;
        last_a = first_a;
        while (last_a->next != NULL)
            last_a = last_a->next;
        stack_a->top = first_a->next;
        first_a->next = NULL;
        last_a->next = first_a;
    }
    if (stack_b != NULL && stack_b->size >= 2)
    {
        first_b = stack_b->top;
        last_b = first_b;
        while (last_b->next != NULL)
            last_b = last_b->next;
        stack_b->top = first_b->next;
        first_b->next = NULL;
        last_b->next = first_b;
    }
    write(1, "rr\n", 3);
}
