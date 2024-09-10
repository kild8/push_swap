#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = get_biggest_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
