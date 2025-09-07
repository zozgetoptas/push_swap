/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:54:53 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:54:53 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

void normalize_stack(t_stack *stack);
long long	ft_atoll(const char *str);
int	handle_errors(char **argv);
void error_exit(void);
int get_position(t_stack *stack, int value);
int get_max_position(t_stack *stack);
int get_min_position(t_stack *stack);
int get_min_value(t_stack *stack);
int get_max_value(t_stack *stack);
int get_value(t_stack *stack, int position);
int get_optimal_rotate_direction(t_stack *stack, int target_value);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void free_stack(t_stack *stack);
int valid_number_control(char *arg);
int doubles_control(long long *args, int count);
int integer_limits_control(long long nmbr);
t_stack *parse_arguments(char **argv);
int get_max_bits(t_stack *a);
void radix_sort(t_stack *a, t_stack *b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
int is_sorted(t_stack *stack);
int is_reverse_sorted(t_stack *stack);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void ra_write(t_stack *stack_a);
void rb_write(t_stack *stack_b);
void sa_write(t_stack *stack_a);
void sb_write(t_stack *stack_b);
void sort_two(t_stack *a);
void sort_three(t_stack *a);
void sort_four(t_stack *a, t_stack *b);
void sort_five(t_stack *a, t_stack *b);

# endif