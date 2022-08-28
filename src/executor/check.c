#include "../../include/minishell.h"

int	check_file_type(const char *command)
{
	struct stat	file_stat;

	if (stat(command, &file_stat))
		return (NOTFOUND);
	if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
		return (DIRECTORY);
	return (COMMON_FILE);
}
