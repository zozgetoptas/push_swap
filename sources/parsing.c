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
void parse_arguments(t_stack *stack_a, char **argv)
{
    int         i = 1;
    int         count = 0;
    long long   *args_ll;
    long long   nmbr;

    count = 0;
    while (argv[count + 1])
        count++;
    args_ll = (long long *)malloc(sizeof(long long) * (count));
    if (!args_ll)
        error_exit();
    while (argv[i])
    {
        if (valid_number_control(argv[i]) == 1)
            error_exit();
        nmbr = ft_atoll(argv[i]);
        if (integer_limits_control(nmbr) == 1)
            error_exit();
            
        // The index for args_ll should be i - 1 because argv[0] is the program name
        args_ll[i - 1] = nmbr; 
        push(stack_a, (int)nmbr);
        i++;
    }
    if (doubles_control(args_ll, count) == 1)
    {
        free(args_ll);
        error_exit();
    }
    free(args_ll);
}
