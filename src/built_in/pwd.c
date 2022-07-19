#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
	{
		free(buf);
		return (0);
	}
	printf("%s", buf);
	free(buf);
	return (1);
}
