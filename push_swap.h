/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:48:35 by hoale             #+#    #+#             */
/*   Updated: 2025/03/06 17:30:38 by hoale            ###   ########.fr       */
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

struct s_node
{
	int	index;
	int	value;
};

struct s_cost
{
	int	cost;
	int	rot_method;
};

# define TRUE 1
# define FALSE 0

int				is_integer(char *str);
int				is_duplicate(t_list *stack);
t_list			*ft_lstnew(int value);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			free_stack(t_list *stack);
void			index_stack(t_list *lst);
struct s_node	max_node(t_list *stack);
struct s_node	min_node(t_list *stack);
int				target4a(int a_value, t_list *sb);
int				target4b(int b_value, t_list *sa);
t_list			*stack_init(char **av, int start);
void			free_arg(char **arg);
int				is_sort(t_list *stack);
void			swap(t_list *stack, char s);
void			ss(t_list *sa, t_list *sb);
void			pa(t_list **sa, t_list **sb);
void			pb(t_list **sa, t_list **sb);
void			rotate(t_list **stack, char s);
void			rr(t_list **sa, t_list **sb);
void			rev_rotate(t_list **stack, char s);
void			rrr(t_list **sa, t_list **sb);
int				max2(int a, int b);
int				min2(int a, int b);
int				min4(int a, int b, int c, int d);
void			upup(t_list **sa, int posa, t_list **sb, int posb);
void			downdown(t_list **sa, int posa, t_list **sb, int posb);
void			updown(t_list **sa, int posa, t_list **sb, int posb);
void			downup(t_list **sa, int posa, t_list **sb, int posb);
struct s_cost	cost_b2top(t_list *sa, t_list *sb, t_list *bnode);
t_list			*cheapest_b(t_list *sa, t_list *sb);
void			cheapb2top(t_list **sa, t_list **sb);
struct s_cost	cost_a2top(t_list *sa, t_list *sb, t_list *anode);
t_list			*cheapest_a(t_list *sa, t_list *sb);
void			cheapa2top(t_list **sa, t_list **sb);
void			sort_three(t_list **stack);
void			min2top(t_list **stack);
void			sort(t_list **sa, t_list **sb);

#endif
