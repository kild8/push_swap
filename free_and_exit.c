#include "push_swap.h"

void	free_and_exit(t_stack **a, t_stack **b, int code)
{
	t_stack *current;
	t_stack	*next;

	current = *a;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	current = *b;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (code == 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}