/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot2top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:14:45 by hoale             #+#    #+#             */
/*   Updated: 2025/02/24 18:08:25 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upup(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;

	i = 0;
	while (i < min2(posa, posb))
	{
		rr(sa, sb);
		i++ ;
	}
	i = 0;
	if (posa >= posb)
	{
		while (i < posa - posb)
		{
			rotate(sa, 'a');
			i++ ;
		}
		return ;
	}
	i = 0;
	while (i < posb - posa)
	{
		rotate(sb, 'b');
		i++ ;
	}
}

//Similar to upup but rr
void	downdown(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;

	i = 0;
	while (i < min2(ft_lstsize(*sa) - posa, ft_lstsize(*sb) - posb))
	{
		rrr(sa, sb);
		i++ ;
	}
	i = 0;
	if (ft_lstsize(*sa) - posa >= ft_lstsize(*sb) - posb)
	{
		while (i < (ft_lstsize(*sa) - posa) - (ft_lstsize(*sb) - posb))
		{
			rev_rotate(sa, 'a');
			i++ ;
		}
		return ;
	}
	while (i < (ft_lstsize(*sb) - posb) - (ft_lstsize(*sa) - posa))
	{
		rev_rotate(sb, 'b');
		i++ ;
	}
}

//Rot a up, rot b down
void	updown(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < posa)
	{
		rotate(sa, 'a');
		i++ ;
	}
	i = 0;
	size_b = ft_lstsize(*sb);
	while (i < size_b - posb)
	{
		rev_rotate(sb, 'b');
		i++ ;
	}
}

//Rot a down, rot b up
void	downup(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;
	int	size_a;

	i = 0;
	while (i < posb)
	{
		rotate(sb, 'b');
		i++ ;
	}
	i = 0;
	size_a = ft_lstsize(*sa);
	while (i < size_a - posa)
	{
		rev_rotate(sa, 'a');
		i++ ;
	}
}
