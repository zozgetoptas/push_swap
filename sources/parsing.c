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
#include "../includes/push_swap.h"

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
		i++;
	}
	return (sign * res);
}

int valid_number_control(char *arg)
{
	int	i;

	i = 0;
	if (!arg || arg[0] == '\0')
		return (1);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (1);
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
t_stack *parse_arguments(char **argv)
{
	int         count = 0;
	t_stack *stack_a;

	while (argv[count + 1])
		count++;
	while (count > 0)
	{
		long long nmbr = ft_atoll(argv[count]);
		push(stack_a, (int)nmbr);
		count--;
	}
	return stack_a;
}
