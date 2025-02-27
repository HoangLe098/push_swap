/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:27 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 18:52:20 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sing_arg(char *arg, t_list **sa)
{
	char	**split_arg;

	split_arg = ft_split(arg, ' ');
	if (!(valid_check(split_arg, 0)))
	{
		free_arg(split_arg);
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	}
	*sa = stack_init(split_arg, 0);
	free_arg(split_arg);
	return (0);
}

static int	mul_arg(char **av, t_list **sa)
{
	if (!(valid_check(av, 1)))
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	*sa = stack_init(av, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*sa;
	t_list	*sb;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (sing_arg(av[1], &sa) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (mul_arg(av, &sa) == EXIT_FAILURE)
			return (EXIT_FAILURE);
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
