#include "../../include/minishell.h"

static void	make_result_from_line(t_split *split, char *line)
{
	int		idx;

	split->i = 0;
	split->j = 0;
	idx = 0;
	split->str = NULL;
	while (line[split->i] != '\0' && idx < split->split_size)
	{
		split_line(split, line);
		split->result[idx] = split->str;
		split->str = NULL;
		idx++;
		split->i++;
	}
}

char	**command_split(char *str)
{
	t_split	*split;

	if (!str)
		return (NULL);
	split = safe_malloc(sizeof(t_split));
	split->result = NULL;
	split->split_size = count_split_size(str);
	split->result = (char **)safe_malloc(sizeof(char *) * (split->split_size + 1));
	split->result[split->split_size] = NULL;
	make_result_from_line(split, str);
	return (split->result);
}
