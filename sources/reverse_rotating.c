#include "push_swap.h"
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
    t_node *first_a;
    t_node *last_a;
    t_node *just_before_the_last_a;
    t_node *first_b;
    t_node *last_b;
    t_node *just_before_the_last_b;

    if (stack_a != NULL && stack_a->size >= 2)
    {
        first_a = stack_a->top;
        just_before_the_last_a = NULL;
        last_a = first_a;
        while (last_a->next != NULL)
        {
            just_before_the_last_a = last_a;
            last_a = last_a->next;
        }
        if (just_before_the_last_a != NULL)
            just_before_the_last_a->next = NULL;
        last_a->next = first_a;
        stack_a->top = last_a;
    }
    if (stack_b != NULL && stack_b->size >= 2)
    {
        first_b = stack_b->top;
        just_before_the_last_b = NULL;
        last_b = first_b;
        while (last_b->next != NULL)
        {
            just_before_the_last_b = last_b;
            last_b = last_b->next;
        }
        if (just_before_the_last_b != NULL)
            just_before_the_last_b->next = NULL;
        last_b->next = first_b;
        stack_b->top = last_b;
    }
    write(1, "rrr\n", 4);
}
