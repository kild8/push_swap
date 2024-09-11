#include "push_swap.h"

void	split_and_fill(char *str, t_stack **a)
{
	int	i;

	i = 0;
	while(str[i])
	{
		while (is_white_space(str[i]))
			i++;
		if (is_number(str[i]) || (is_sign(str[i])))
			convert(str + i, a);
		else
			free_and_exit(a, NULL, 1);
		while (is_number(str[i]) || (is_sign(str[i])))
			i++;
		if (str[i] && (!is_white_space(str[i])))
			free_and_exit(a, NULL, 1);
	}
}

void	convert(char *str, t_stack **a)
{
	t_stack	*new;

	new = initiate_node(ft_atoi(str, a));
	if (!new)
		free_and_exit(a, NULL, 1);
	add_node_to_stack(a, new);
}

void	add_node_to_stack(t_stack **a, t_stack *node)
{	
	t_stack *current;

	if (*a == NULL)
		*a = node;
	else
	{
	current = get_last_node(*a);
	current->next = node;
	}
}

int	ft_atoi(const char *argv, t_stack **a)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (is_white_space(argv[i]))
		i++;
	while (argv[i] == '+' || argv[i] == '-')
	{
		if(argv[i] == '-')
			sign = -sign;
		i++;
	}
	while (is_number(argv[i]))
	{
		res = res * 10 + (argv[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			free_and_exit(a, NULL, 1);
		i++;
	}
	return (int)(res * sign);
}
