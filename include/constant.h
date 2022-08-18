#ifndef CONSTANT_H
# define CONSTANT_H

enum e_token_type
{
	TK_EOF,
	TK_RDINPUT,
	TK_RDOUTPUT,
	TK_APPEND,
	TK_PIPE,
	TK_COMMAND,
	TK_FILE,
	TK_HEREDOC,
	TK_DELIM,
	TK_WORD
};

enum file_type
{
	READ,
	WRITE,
	APPEND
};

enum e_boolean {
	FAILURE = 0,
	SUCCESS = 1,
};

enum e_env_key_result {
	ENV_KEY_OTHERS = 1,
	ENV_KEY_QUESTION = 2,
};

# define CD "cd"
# define ENV "env"
# define PWD "pwd"
# define EXIT "exit"
# define ECHO "echo"
# define UNSET "unset"
# define EXPORT "export"

# define TRUE 1
# define FALSE 0

#endif