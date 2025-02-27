/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:27 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 18:28:23 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*sa;
	t_list	*sb;
	char	**arg;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!(valid_check(arg, 0)))
			return (write(2, "Error\n", 6), EXIT_FAILURE);
		sa = stack_init(arg, 0);
		free_arg(arg);
	}
	else
	{
		if (!(valid_check(av, 1)))
			return (write(2, "Error\n", 6), EXIT_FAILURE);
		sa = stack_init(av, 1);
	}
	sb = NULL;
	if (is_duplicate(sa))
	{
		free_stack(sa);
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	}
	sort(&sa, &sb);
	free_stack(sa);
	return (0);
}
