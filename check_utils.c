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
