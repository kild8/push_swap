#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*head;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	head = *a;
	second = (*a)->next;
	head->next = second->next;
	second->next = head;
	*a = second;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **a)
{
	swap(a);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}