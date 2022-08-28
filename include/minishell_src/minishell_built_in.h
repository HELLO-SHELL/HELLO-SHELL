#ifndef MINISHELL_BUILT_IN_H
# define MINISHELL_BUILT_IN_H

/* built-in */
int	ft_pwd(void);
int	ft_env(void);
int	ft_cd(void);
int	ft_unset(void);
int	ft_exit(void);
int	ft_echo(char **argv);
int	ft_export(t_token *cmd_line);

#endif