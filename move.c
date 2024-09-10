#include "push_swap.h"

void	move(t_stack *node, t_stack **a, t_stack **b)
{
	if (node->do_r == 1)
		do_rotate(node, a, b);
	else if (node->do_rr == 1)
		do_rev_rotate(node, a, b);
	pb(a, b);
}

void	do_rotate(t_stack *node, t_stack **a, t_stack **b)
{
	while (node->r > 0 && node->rb > 0)
		{
			rr(a, b);
			node->r--;
			node->rb--;
		}
	while (node->r > 0)
		{
			ra(a);
			node->r--;
		}
	while(node->rb > 0)
		{
			rb(b);
			node->rb--;
		}
}

void	do_rev_rotate(t_stack *node, t_stack **a, t_stack **b)
{	
	while (node->rr > 0 && node->rrb > 0)
		{
			rrr(a, b);
			node->rr--;
			node->rrb--;
		}
	while (node->rr > 0)
		{
			rra(a);
			node->rr--;
		}
	while(node->rb > 0)
		{
			rrb(b);
			node->rrb--;
		}
}
