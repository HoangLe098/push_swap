/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:12 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 15:13:27 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*elem;

	elem = (t_list *)malloc(1 * sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++ ;
	}
	return (i);
}

void	free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	current = stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	index_stack(t_list *lst)
{
	t_list	*iter;
	int		i;

	if (!lst)
		return ;
	iter = lst;
	i = 0;
	while (iter)
	{
		iter->index = i;
		iter = iter->next;
		i++ ;
	}
}
