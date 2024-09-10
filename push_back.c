#include "push_swap.h"

void	push_back(t_stack **a, t_stack **b)
{
	t_stack	*last_a;

	last_a = get_last_node(*a);
	while (*b && (*b)->value > last_a->value)
		pa(a, b);
	rra(a);
	last_a = get_last_node(*a);
	while (*b && (*b)->value > last_a->value)
		pa(a, b);
	rra(a);
	last_a = get_last_node(*a);
	while (*b && (*b)->value > last_a->value)
		pa(a, b);
	rra(a);
	while (*b)
		pa(a, b);
}

void	order_a(t_stack **a)
{
	t_stack	*current;
	int		smallest_value;
	int		position;
	int		i;

	current = *a;
	smallest_value = INT_MAX;
	position = 0;
	i = 0;
	while (current)
	{
		if (current->value < smallest_value)
		{
			smallest_value = current->value;
			position = i;
		}
		current = current->next;
		i++;
	}
	while (position-- > 0)
		ra(a);
}

void	order_b(t_stack **b)
{
	t_stack	*current;
	int		biggest_value;
	int		position;
	int		i;

	current = *b;
	biggest_value = INT_MIN;
	position = 0;
	i = 0;
	while (current)
	{
		if (current->value > biggest_value)
		{
			biggest_value = current->value;
			position = i;
		}
		current = current->next;
		i++;
	}
	while (position-- > 0)
		rb(b);
}