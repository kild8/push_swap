#include "push_swap.h"

void	fill(int argc, char **argv, t_stack **a)
{
	int 	i;
	t_stack	*node;
	t_stack	*last;

	i = 1;
	last = NULL;
	node = malloc(sizeof(t_stack));
	if (!node)
		free_and_exit(NULL, NULL, 1);
	node->value = ft_atoi(argv[i]);
	node->next = NULL;
	*a = node;
	last = node;
	i++;
	while (i < argc)
	{
		node = initiate_node(ft_atoi(argv[i]));
		if (!node)
			free_and_exit(a, NULL, 1);
		last->next = node;
		last = node;
		i++;
	}
}

t_stack	*initiate_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->r = 0;
	node->rr = 0;
	node->rb = 0;
	node->rrb = 0;
	node->do_r = 0;
	node->do_rr = 0;
	node->next = NULL;
	return (node);
}
