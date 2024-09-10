#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack *top;
	t_stack *last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	top = *a;
	last = get_last_node(*a);
	*a = (*a)->next;
	last->next = top;
	top->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

t_stack	*get_last_node(t_stack *a)
{
	t_stack *current;

	if (a == NULL)
		return (NULL);
	current = a;
	while (current->next)
	{
		current = current->next;
	}
		return (current);
}