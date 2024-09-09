#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stddef.h>
#include <unistd.h>

typedef struct	s_stack
{
	int				value;
	int				index;
	int				r;
	int				rr;
	int				rb;
	int				rrb;
	int				do_r;
	int				do_rr;
	struct s_stack	*next;
}	t_stack;

bool	check_arg(int argc, char **argv);
bool	check_max(char *argv);
bool	is_number(char c);
bool	is_white_space(char c);
bool	is_sign(char c);
void	check_double(t_stack **a);
void	fill(int argc, char **argv, t_stack **a);
t_stack	*initiate_node(int value);
void	free_and_exit(t_stack **a, t_stack **b, int code);
void	move(t_stack *node, t_stack **a, t_stack **b);
void	do_rotate(t_stack *node, t_stack **a, t_stack **b);
void	do_rev_rotate(t_stack *node, t_stack **a, t_stack **b);
void	push_back(t_stack **a, t_stack **b);
void	order_a(t_stack **a);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **a);
t_stack	*get_second_last_node(const t_stack *a);
void	rra(t_stack	**a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rotate(t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
t_stack	*get_last_node(t_stack *a);
void	sort_three(t_stack **a);
int		stack_length(t_stack *a);
t_stack	*get_biggest_node(t_stack *a);
void	give_index(t_stack **a);
int		find_position(t_stack *a, t_stack *target);
void	sort(t_stack **a, t_stack **b);
void	sort_algorithm(t_stack **a, t_stack **b);
int		find_target(t_stack *a, t_stack *b);
void	calculate_cost(t_stack **a, t_stack **b);
t_stack	*set_cheapest(t_stack **a, t_stack **b);
int		set_move(t_stack *current);
void	split_and_fill(char *argv, t_stack **a);
int		ft_strlen(const char *s);
void	add_node_to_stack(t_stack **a, t_stack *node);
int		ft_atoi(const char *argv);
void	swap(t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);

#endif