#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	if (argc == 1)
		free_and_exit(NULL, NULL, 1);
	if (argc == 2)
		split_and_fill(argv[1], &a);
	else if (argc > 2)
		fill(argc, argv, &a);
	check_double(&a);
	sort(&a, &b);
	free_and_exit(&a, &b, 0);
	return (0);
}
