#include "push_swap.h"

void	free_and_exit(t_stack **a, t_stack **b, int code)
{
	t_stack *temp;

	if (a != NULL)
	{
		while (*a != NULL)
		{
			temp = *a;
			*a = (*a)->next;
			free(temp);
		}
	}
	if (b != NULL)
	{
		while (*b != NULL)
		{
			temp = *b;
			*b = (*b)->next;
			free(temp);
		}
	}
	if (code == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}