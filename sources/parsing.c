/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:40 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:40 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int		sign;
	long long		res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
        if ((res * sign > INT_MAX) || (res * sign < INT_MIN))
            error_exit();
        i++;
	}
	return (sign * res);
}

int valid_number_control(char *arg)
{
    int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
int doubles_control(long long *args, int count)
{
    int i = 0;
    int j;
	while (i < count - 1)
    {
        j = i + 1;
        while (j < count)
        {
            if (args[i] == args[j])
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int integer_limits_control(long long nmbr)
{
    if (nmbr > INT_MAX || nmbr < INT_MIN)
        return (1);
    return (0);
}
void parse_arguments(t_stack *stack_a, char **argv)
{
    int         i = 1;
    int         count = 0;
    long long   *args_ll;
    long long   nmbr;

    while (argv[count + 1])
        count++;
    args_ll = (long long *)malloc(sizeof(long long) * count);
    if (!args_ll)
        error_exit();
    while (argv[i])
    {
        if (valid_number_control(argv[i]) == 0)
        {
            free(args_ll);
            error_exit();
        }
        nmbr = ft_atoll(argv[i]);
        args_ll[i - 1] = nmbr;
        i++;
    }
    if (doubles_control(args_ll, count) == 1)
    {
        free(args_ll);
        error_exit();
    }
    i = count - 1;
    while (i >= 0)
    {
        push(stack_a, (int)args_ll[i]);
        i--;
    }
    free(args_ll);
}
