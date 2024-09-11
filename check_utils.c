#include "push_swap.h"

bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
		return (true);
	return (false);
}

bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

bool	is_sorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if (current->next)
		{
			if (current->value > current->next->value)
				return (false);
		}
		current = current->next;
	}
	return (true);
}
