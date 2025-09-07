/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:53:29 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/05 16:53:29 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int handle_errors(char **argv)
{
    int i = 1;
    int count = 0;
    long long *args_ll;

	while (argv[i])
        i++;
    count = i - 1;

    if(count == 0)
	{
        return 0;
    }
	args_ll = malloc(sizeof(long long) * count);
    if (!args_ll)
	{
		error_exit();
	}
        
	i = 1;
    while (argv[i])
    {
        if (valid_number_control(argv[i]))
        {
            free(args_ll);
            return 1;
        }
        args_ll[i - 1] = ft_atoll(argv[i]);
        if (integer_limits_control(args_ll[i - 1]))
        {
            free(args_ll);
            error_exit();
        }
        i++;
    }
    if (doubles_control(args_ll, count))
    {
        free(args_ll);
        error_exit();
    }
    
    free(args_ll);
    return 0;
}

void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}