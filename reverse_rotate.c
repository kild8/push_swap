#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*sec_last;
	t_stack	*last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	last = get_last_node(*a);
	sec_last = get_second_last_node (*a);
	last->next = *a;
	sec_last->next = NULL;
	*a = last;
}

t_stack	*get_second_last_node(const t_stack *a)
{
	t_stack	*current;

	current = a;
	if (a == NULL || a->next == NULL)
		return (NULL);
	while (current->next->next != NULL)
		current = current->next;
	return (current);
}

void	rra(t_stack	**a)
{
	rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rotate(b);
	write(1, "rrb\n", 4);

}

void	rrr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rrr\n", 4);
}
