/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:27 by hoale             #+#    #+#             */
/*   Updated: 2025/03/03 19:25:27 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_arg(char **av, t_list **sa)
{
	int		i;
	int		j;
	char	**split_arg;

	i = 1;
	while (av[i])
	{
		split_arg = ft_split(av[i], ' ');
		j = 0;
		while (split_arg[j])
		{
			if (is_integer(split_arg[j]) == FALSE)
			{
				free_arg(split_arg);
				free_stack(*sa);
				return (write(2, "Error\n", 6), EXIT_FAILURE);
			}
			ft_lstadd_back(sa, ft_lstnew(ft_atoi(split_arg[j])));
			index_stack(*sa);
			j++ ;
		}
		free_arg(split_arg);
		i++ ;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*sa;
	t_list	*sb;

	if (ac == 1)
		return (0);
	sa = NULL;
	sb = NULL;
	if (handle_arg(av, &sa) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_duplicate(sa) == TRUE || sa == NULL)
	{
		free_stack(sa);
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	}
	if (is_sort(sa) == TRUE)
	{
		free_stack(sa);
		return (0);
	}
	sort(&sa, &sb);
	free_stack(sa);
	return (0);
}
