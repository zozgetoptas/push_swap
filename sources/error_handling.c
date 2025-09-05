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

int	handle_errors(char **argv)
{
	int i = 1;
	if (doubles_control(argv))
		return 1;
	while(argv[i])
	{
		if (valid_number_control(argv[i]))
			return 1;
		i++;
	}
	return (0);
}
void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}