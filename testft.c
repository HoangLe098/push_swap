/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:42:55 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 16:45:22 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_lst(t_list *stack)
{
    t_list  *ptr;

    ptr = stack;
    while (ptr)
    {
        ft_printf("Index: %i\nValue: %i\n|\nV\n", ptr->index, ptr->value);
        ptr = ptr->next;
    }
    ft_printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_list	*sa;
	t_list	*sb;

	if (ac <= 1)
		return (ft_printf("Error\n"), EXIT_FAILURE);
	if (valid_check(av) == FALSE)
		return (ft_printf("Error\n"), EXIT_FAILURE);
	sa = stack_init(av);
	sb = NULL;
	if (is_duplicate(sa))
	{
		free_stack(sa);
		return (ft_printf("Error\n"), EXIT_FAILURE);
	}
    sort(&sa, &sb);
    print_lst(sa);
    free_stack(sa);
}
