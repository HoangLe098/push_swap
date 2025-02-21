#include "push_swap.h"

int	max(int count, ...)
{
	int	*args;
	int	max_value;
	int	i;

	args = &count + 1;
	max_value = *args;
	i = 1;
	while (i < count)
	{
		if (*(args + i) > max_value)
			max_value = *(args + i);
		i++ ;
	}
	return (max_value);
}

int	min(int count, ...)
{
	int	*args;
	int	min_value;
	int	i;

	args = &count + 1;
	min_value = *args;
	i = 1;
	while (i < count)
	{
		if (*(args + i) < min_value)
			min_value = *(args + i);
		i++ ;
	}
	return (min_value);
}
