#include "../includes/push_swap.h"

// 2 elemanlı bir yığını sıralar
void sort_two(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a);
}

// 3 elemanlı bir yığını sıralar
void sort_three(t_stack *a)
{
    int max = get_max_value(a);

    if (a->top->value == max)
        ra(a);
    else if (a->top->next->value == max)
        rra(a);
    if (a->top->value > a->top->next->value)
        sa(a);
}

// 4 elemanlı bir yığını sıralar
void sort_four(t_stack *a, t_stack *b)
{
    int min_pos = get_min_position(a);
    if (min_pos <= a->size / 2)
    {
        while (min_pos--)
            ra(a);
    }
    else
    {
        while (min_pos++ < a->size)
            rra(a);
    }
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

// 5 elemanlı bir yığını sıralar
void sort_five(t_stack *a, t_stack *b)
{
    int min_pos;
    int direction;

    while (a->size > 3)
    {
        min_pos = get_min_position(a);
        direction = get_optimal_rotate_direction(a, get_value(a, min_pos));
        
        if (direction == 1) // ra
        {
            while (min_pos--)
                ra(a);
        }
        else // rra
        {
            while (min_pos++ < a->size)
                rra(a);
        }
        pb(a, b);
    }
    sort_three(a);
    while (b->size > 0)
        pa(a, b);
}