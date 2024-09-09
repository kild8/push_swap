#include "push_swap.h"

void	check_double(t_stack **a)
{
	t_stack	*current;
	t_stack	*comp;
	int		current_value;
	int		comp_value;

	current	= *a;
	comp = (*a)->next;
	current_value = current->value;
	comp_value = comp->value;
	while (current)
	{
		current_value = current->value;
		comp = current->next;
		while (comp)
		{
			comp_value = comp->value;
			if (current_value == comp_value)
				free_and_exit(a, NULL, 1);
			comp = comp->next;
		}
		current = current->next;
	}
	return ;
}
