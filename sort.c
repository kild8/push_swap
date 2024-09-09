#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (stack_length(*a) > 3)
		pb(a, b);
	if (stack_length(*a) > 3)
		pb(a, b);
	if (stack_length(*a) == 3)
		sort_three(a);
	else
		sort_algorithm(a, b);
	push_back(a, b);
	order_a(a);
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = NULL;
	while (stack_length(a) > 3)
	{
		give_index(a);
		give_index(b);
		calculate_cost(a, b);
		node = set_cheapest(a, b);
		move(node, a, b);
	}
	sort_three(a);
}


int	find_target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*best_match;

	current = b;
	best_match = NULL;

	while (current)
	{
		if (current->value < a->value)
		{
			if (!best_match || current->value > best_match->value)
			best_match = current;
		}
		current = current->next;
	}
	if (best_match)
		return (find_position(b, best_match));
	else
		return (find_position(b, (get_biggest_node(b))));
}

void	calculate_cost(t_stack **a, t_stack **b)
{
	t_stack *current;
	t_stack *target;
	int		length_a;
	int		length_b;

	current = *a;
	target = NULL;
	length_a = stack_length(*a);
	length_b = stack_length(*b);
	while (current)
	{
		target = find_target(current, *b);
		current->r = current->index;
		current->rr = length_a - current->index;
		current->rb = target->index;
		current->rrb = length_b - target->index;
		current = current->next;
	}
}

t_stack	*set_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack *cheapest_a;
	int		move;
	int		cheapest;

	current = *a;
	cheapest_a = NULL;
	move = 0;
	cheapest = INT_MAX;
	while (current)
	{
		move = set_move(current);
		if (move < cheap)
		{
			cheapest = move;
			cheapest_a = current;
		}
		current = current->next;
	}
	return (cheapest_a);
}

int	set_move(t_stack *current)
{
	int	move;

	move = 0;
	if (current->r + current->rb < current->rr + current->rrb)
		{
			current->do_r = 1;
			current->do_rr = 0;
			if (current->r >= current->rb)
				move = current->r;
			else
				move = current->rb;
		}
	else
		{
			current->do_rr = 1;
			current->do_r = 0;
			if (current->rr >= current->rrb)
				move = current->rr;
			else
				move = current->rrb;
		}
	return (move);
}
