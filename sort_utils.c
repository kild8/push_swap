#include "push_swap.h"

int	stack_length(t_stack *a)
{
	int	i;
	t_stack	*current;

	i = 0;
	current = a;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_stack	*get_biggest_node(t_stack *a)
{
	t_stack	*biggest;
	t_stack	*current;

	current = a;
	biggest = a;
	while (current)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	give_index(t_stack **a)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = *a;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

int	find_position(t_stack *a, t_stack *target)
{
	t_stack	*current;
	int	position;

	current = a;
	position = 1;
	while (current && current != target)
	{
		current = current->next;
		position++;
	}
	if (current == target)
		return position;
	else
		return (-1);
}
