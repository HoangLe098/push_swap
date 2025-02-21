
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac <= 1)
		return (ft_printf("Error\n"), EXIT_FAILURE);
	if (!(valid_check(av))
		return (ft_printf("Error\n"), EXIT_FAILURE);
	stack_a = stack_init(av);
	if (is_sort(stack_a) || is_repeat(stack_a))
	{
		free_stack(stack_a);
		return (ft_printf("Error\n"), EXIT_FAILURE);
	}
}