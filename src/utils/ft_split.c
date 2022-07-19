static int	check_rest(char **av, int i, int j)
{
	while (0 != av[i][j])
	{
		if ((9 <= av[i][j] && 13 >= av[i][j]) || av[i][j] == 32)
		{
			if (av[i][j + 1] == 0)
				return (1);
			j++;
		}
		else
			return (0);
	}
	return (1);
}

static void	ft_second_split(char **result, char **av)
{
	int		i;
	int		j;
	int		index;
	int		position;

	i = 1;
	index = 0;
	while (0 != av[i])
	{
		j = 0;
		while (0 != av[i][j])
		{
			position = j;
			j = check_size(av, i, j);
			create_result(result, &index, &j, &position);
			if (check_index(result, index))
				break ;
			make_str(result[index], av[i], position, j - position);
			if (0 == av[i][j] || check_rest(av, i, j))
				break ;
			index++;
		}
		index++;
		i++;
	}
}

char	**ft_split(char **av)
{
	int		split_size;
	int		i;
	char	**result;

	result = 0;
	i = 0;
	split_size = count_size(av);
	result = (char **)malloc(sizeof(char *) * split_size + 1);
	if (result == 0)
		return (0);
	result[split_size + 1] = 0;
	ft_second_split(result, av);
	return (result);
}
