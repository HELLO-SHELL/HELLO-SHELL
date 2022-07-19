void	make_result_from_line(char **result, char *line, int size)
{
	int		i;
	int		idx;
	char	*str;

	i = 0;
	idx = 0;
	str = NULL;
	while (line[i] != '\0' && idx < size)
	{
		if (!check_size(line, &str, &i))
			break;
		printf("%dst split_size %s\n", i,str);
		result[idx] = str;
		str = NULL;
		idx++;
		i++;
	}
}

char	**ft_split(char *str)
{
	int		split_size;
	char	**result;

	if (!str)
		return (NULL);
	result = NULL;
	split_size = count_split_size(str);
	result = (char **)malloc(sizeof(char *) * split_size + 1);
	if (result == NULL)
		exit (1);
	result[split_size + 1] = NULL;
	make_result_from_line(result, str, split_size);
	return (result);
}
