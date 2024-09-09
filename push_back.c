#include "push_swap.h"

void	push_back(t_stack **a, t_stack **b)
{
	t_stack	*last_a;

	last_a = get_last_node(*a);
	while ((*b)->value > last_a->value && stack_length(*b) > 0)
		pa(a, b);
	rra(a);
	last_a = get_last_node(*a);
	while ((*b)->value > last_a->value && stack_length(*b) > 0)
		pa(a, b);
	rra(a);
	last_a = get_last_node(*a);
	while ((*b)->value > last_a->value && stack_length(*b) > 0)
		pa(a, b);
	rra(a);
	while (stack_length(b) > 0)
		pa(a, b);
}

void	order_a(t_stack **a)
{
	t_stack	*current;
	int	smallest_value;
	
	current = *a;
	smallest_value = INT_MAX;
	while (current)
	{
		if (current->value < smallest_value)
			smallest_value = current->value;
		current = current->next;
	}
	while (*a->value != smallest_value)
		ra(a);
}
