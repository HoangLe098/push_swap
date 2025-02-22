/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:48:35 by hoale             #+#    #+#             */
/*   Updated: 2025/02/22 16:27:29 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/printf.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct node
{
	int	index;
	int	value;
}

typedef struct cost
{
	int	cost;
	int	rot_method;
}

# define TRUE = 1
# define FALSE = 0

int		valid_check(char **av);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_stack(t_list *stack);
void	index_stack(t_list *lst);
node	max_node(t_list *stack);
node	min_node(t_list *stack);
int		target4a(int a_value, t_list *sb);
int		target4b(int b_value, t_list *sa);
t_list	*stack_init(char **av);
int		is_sort(t_list *stack);
int		is_duplicate(t_list *stack);
void	swap(t_list *stack, char s);
void	ss(t_list *sa, t_list *sb);
void	pa(t_list **sa, t_list **sb);
void	pb(t_list **sa, t_list **sb);
void	rotate(t_list **stack, char s);
void	rr(t_list **sa, t_list **sb);
void	rev_rotate(t_list **stack, char s);
void	rrr(t_list **sa, t_list **sb);
int		max(int count, ...);
int		min(int count, ...);
void	upup(t_list **sa, int posa, t_list **sb, int posb);
void	downdown(t_list **sa, int posa, t_list **sb, int posb);
void	updown(t_list **sa, int posa, t_list **sb, int posb);
void	downup(t_list **sa, int posa, t_list **sb, int posb);

#endif
