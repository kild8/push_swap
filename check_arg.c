#include "push_swap.h"

bool	check_arg(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		free_and_exit(NULL, NULL, 1);
	while (i < argc)
	{
		if (check_max(argv[i]) == false)
			free_and_exit(NULL, NULL, 1);
		i++;
	}
	return (true);
}

bool	check_max(char *argv)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while(is_white_space(argv[i]))
		i++;
	if (is_sign(argv[i]))
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (false);
		if (res > (INT_MAX - (argv[i] - '0')) / 10)
			return (false);
		res = res * 10 + (argv[i] - '0');
		i++;
	}
	res = res * sign;
		if (res > INT_MAX || res < INT_MIN)
			return (false);
	return (true);
}

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
