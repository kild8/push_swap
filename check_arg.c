#include "push_swap.h"

bool	check_arg(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		free_and_exit(NULL, NULL, 1);
	if (argc == 2)
	{
		if (check_string(argv[1]) == false)
			free_and_exit(NULL, NULL, 1);
	}
	else
	{
		while (i < argc)
		{
			if (check_max(argv[i]) == false)
				free_and_exit(NULL, NULL, 1);
			i++;
		}
	}
	return (true);
}

bool	check_string(char *argv)
{
 	int		i;
	int		flag;

    i = 0;
    flag = -1;
    while (i < ft_strlen(argv))
    {
        if (argv[i] != ' ' && flag < 0)
            flag = i;
        else if ((is_white_space(argv[i]) || i == ft_strlen(argv)) && flag >= 0)
        {
			argv[i] = '\0';
			if (!(check_max(&argv[flag])))
				return (false);
			flag = - 1;		
        }
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
