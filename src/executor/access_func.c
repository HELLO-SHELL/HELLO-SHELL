#include "../../include/minishell.h"

int	is_file(char *path)
{
	struct stat buf;
    int kind;

    stat(path, &buf);
    printf("Mode = %o (16진수: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    kind = buf.st_mode & S_IFMT;
    printf("Kind = %x\n", kind);

    switch (kind) {
        case S_IFIFO:
            printf("unix.txt : FIFO\n");
            break;
        case S_IFDIR:
            printf("unix.txt : Directory\n");
            break;
        case S_IFREG:
            printf("unix.txt : Regular File\n");
            break;
    }
	return (TRUE);
}

int	is_writable_file(char *filename);
int	is_exist_file(char *filename);
int	is_readable_file(char *filename);
int	is_executable_command(char *command);
