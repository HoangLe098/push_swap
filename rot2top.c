#include "push_swap.h"

void	upup(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;

	i = -1;
	while (i++ < min(2, posa, posb))
		rr(sa, sb);
	i = -1;
	if (posa >= posb)
	{
		while (i++ < posa - posb)
			rotate(sa);
		return;
	}
	while (i++ < posb - posa)
		rotate(sb);
}

//Similar to upup but rr
void	downdown(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;
	int	bota;
	int	botb;

	bota = ft_lstsize(*sa) - posa;
	botb = ft_lstsize(*sb) - posb;
	i = -1;
	while (i++ < min(2, bota, botb))
		rrr(sa, sb);
	i = -1;
	if (bota >= botb)
	{
		while (i++ < bota - botb)
			rev_rotate(sa);
		return;
	}
	while (i++ < botb - bota)
		rev_rotate(sb);
}

//Rot a up, rot b down
void	updown(t_list **sa, int posa, t_list **sb, int posb)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < posa)
	{
		rotate(sa);
		i++ ;
	}
	i = 0;
	size_b = ft_lstsize(*sb);
	while (i < size_b - posb)
	{
		rotate(sb);
		i++ ;
	}
}

//Rot a down, rot b up
void	downup(t_list **sa, int posa, t_list **sb, int posb)
{

}
