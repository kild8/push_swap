#include "push_swap.h"

void	split_and_fill(char *argv, t_stack **a)
{
    int		i;
	int		flag;
    t_stack	*node;

    node = NULL;
    i = 0;
    flag = -1;
    while (i <= ft_strlen(argv))
    {
        if (argv[i] != ' ' && flag < 0)
            flag = i;
        else if ((is_white_space(argv[i]) || i == ft_strlen(argv)) && flag >= 0)
        {
			argv[i] = '\0';
			node = initiate_node(ft_atoi(&argv[flag]));
			if (node == NULL)
				free_and_exit(a, NULL, 1);
            add_node_to_stack(a, node);
			flag = - 1;		
        }
        i++;
    }
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

int	ft_atoi(const char *argv)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (is_white_space(argv[i]))
		i++;
	if (argv[i] == '+' || argv[i] =='-')
	{
		if(argv[i] == '-')
			sign = -sign;
		i++;
	}
	while (is_number(argv[i]))
	{
		res = res * 10 + (argv[i] - '0');
		i++;
	}
	return (res * sign);
}
