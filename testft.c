/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:42:55 by hoale             #+#    #+#             */
/*   Updated: 2025/02/22 17:14:24 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    print_lst(t_list *stack)
{
    t_list  *ptr;

    ptr = stack;
    while (ptr)
    {
        printf("Index: %i\nValue: %i\n|\nV\n", ptr->index, ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void    print_2lst(t_list *sa, t_list *sb)
{
    t_list  *pa;
    t_list  *pb;

    pa = sa;
    pb = sb;
    while (pa && pb)
    {
        printf("i: %i\ti: %i\nv: %i\tv: %i\n|\nV\n", pa->index, pb->index, pa->value, pb->value);
        pa = pa->next;
        pb = pb->next;
    }
    if (pa && !pb)
    {
        printf("i: %i\tNULL\nv: %i\n|\nV\n", pa->index, pa->value);
        pa = pa->next;
        while (pa)
        {
            printf("i: %i\nv: %i\n|\nV\n", pa->index, pa->value);
            pa = pa->next;
        }
        printf("NULL\n");
    }
    else if (!pa && pb)
    {
        printf("NULL\ti: %i\nv: %i", pb->index, pb->value);
        pb = pb->next;
        while (pb)
        {
            printf("\t\ti: %i\n\t\tv: %i\n\t\t|\n\t\tV\n", pa->index, pa->value);
            pb = pb->next;
        }
        printf("\t\tNULL\n");
    }
}
