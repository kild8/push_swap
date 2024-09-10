//le but cest de recevoir un string et le decouper en plusieurs elements.
tant que ces elements sont des nombres, tout va bien
si ce ne sont pas des nombres on renvoie le programme

void	split_and_fill(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		while (is_white_space(str[i]))
			i++;
		if (is_number(str[i]) || (is_sign(str[i]) && is_number(str[i + 1])))
			convert(str + i);
		else
			free_and_exit(a, NULL, 1);
		while (is_number(str[i]))
			i++;
		if (str[i] && !is_white_space(str[i]))
			free_and_exit(a, NULL, 1);
	}
}

void	convert(char *str)
{
	int	value;
	t_stack	*new;

	new = init_node;
	value = ft_atoi(str)
	check_max(str);
	new->value = value;
}

le atoi
le passe en stack
passe au nbre suivant
	
	
	while str[i] is number


}

int	count(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (is_white_space(str[i]))
			i++;
		if (is_number(str[i]) || (is_sign(str[i]) && is_number(str[i + 1])))
			count++;
		while (is_number(str[i]))
			i++;
		while (str[i] && !is_number(str[i]) && !is_white_space(str[i]))
			i++;
	}
	return (count);
}