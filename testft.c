/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:42:55 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 18:28:35 by hoale            ###   ########.fr       */
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

void    print_2lst(t_list *sa, t_list *sb)
{
    t_list  *pa;
    t_list  *pb;

    pa = sa;
    pb = sb;
    while (pa && pb)
    {
        ft_printf("i: %i\ti: %i\nv: %i\tv: %i\n|\nV\n", pa->index, pb->index, pa->value, pb->value);
        pa = pa->next;
        pb = pb->next;
    }
    if (pa && !pb)
    {
        ft_printf("i: %i\tNULL\nv: %i\n|\nV\n", pa->index, pa->value);
        pa = pa->next;
        while (pa)
        {
            printf("i: %i\nv: %i\n|\nV\n", pa->index, pa->value);
            pa = pa->next;
        }
        ft_printf("NULL\n\n");
    }
    else if (!pa && pb)
    {
        ft_printf("NULL\ti: %i\nv: %i", pb->index, pb->value);
        pb = pb->next;
        while (pb)
        {
            printf("\t\ti: %i\n\t\tv: %i\n\t\t|\n\t\tV\n", pa->index, pa->value);
            pb = pb->next;
        }
        ft_printf("\t\tNULL\n\n");
    }
	else if (!pa && !pb)
		ft_printf("NULL\tNULL\n\n");
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
	pb(&sa, &sb);
	pb(&sa, &sb);
	while (ft_lstsize(sa) > 3)
	{
		cheapb2top(&sa, &sb);
		pb(&sa, &sb);
	}
	print_lst(sa);
	sort_three(&sa);
	print_lst(sa);
	free_stack(sa);
	free_stack(sb);
	sa = NULL;
	sb = NULL;
}
