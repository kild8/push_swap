#include "push_swap.h"

void	split_and_fill(char *argv, t_stack **a)
{
    t_stack	*node;
	char	*token;
	char	*copy;

    node = NULL;
	copy = ft_strdup(argv);
	token = ft_strtok(copy, " ");
    while (token != NULL)
	{	
		node = initiate_node(ft_atoi(token));
		if (node == NULL)
		{
			free(copy);
			free_and_exit(a, NULL, 1);
		}
        add_node_to_stack(a, node);
		token = ft_strtok(NULL, " ");	
	}
	free(copy);
}

char	*ft_strtok(char *str, char *delim)
{
	static char	*saveptr = NULL;
	char		*token;

	token = NULL;
	if (str != NULL)
		saveptr = str;
	if (saveptr == NULL)
		return (NULL);
	while (*saveptr != '\0' && ft_strchr(delim, *saveptr) != NULL)
		saveptr++;
	if (*saveptr == '\0')
		return (NULL);
	token = saveptr;
	while (*saveptr != '\0' && ft_strchr(delim, *saveptr) == NULL)
		saveptr++;
	if (*saveptr != '\0')
		*saveptr++ = '\0';
	return (token);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	return (NULL);
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
