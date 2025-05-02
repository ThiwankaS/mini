#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../ft_libft/libft.h"
# include "../ft_libft/ft_printf.h"
# include "../ft_libft/get_next_line.h"

# define SMPL_CMD 1 // For simple command
# define OPRD_CMD 2 // For output redirect command ">"
# define APRD_CMD 3 // For output redirect append command ">>"
# define IPRD_CMD 4 // For input redirect command "<"
# define HDRD_CMD 5 // For input heredoc redirect command "<<"

# define CACHE "cache.txt"
# define ISSPACE " \f\n\t\r\v"

/**
 * data node strucutre to hold the tokens extract from input, this node will make a linked list
*/
typedef struct s_list
{
	char 			*token;
	struct s_list 	*next;
} t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	int 			type;
	char			*filename;
	char 			*cmd;
	char 			*command;
	char 			**args;
	int 			num_args;
	struct s_cmd 	*next;
} t_cmd;

typedef struct s_shell
{
	int			num_cmds;
	int			status;
	char		**envp;
	t_cmd		*cmds;
	t_list		*tokens;
	t_env		*env;
} t_shell;

/**
 * Implementation in srcs/main.c
*/

/**
 * TO DO
 * norminette
 * Error: TOO_MANY_LINES       (line: 101, col:   1):	Function has more than 25 lines
*/

/**
 * Implementation in srcs/utils/error.c
*/
int		syntax_error(char *input, char *msg, int code);

/**
 * Implementation in srcs/utils/helper.c
*/
int		activate_shell(t_shell *mini, char *input);
void	init_mini_shell(t_shell *mini, char **envp);

/**
 * Implementation in srcs/utils/utils.c
*/
int		ft_isspace(int c);
int		ft_isempty(char *str);
int		ft_lst_len(t_env *env);
int		ft_arraylen(char **envp);
int		quotes_checker(char *input, int len);
int		ft_strnmcpy(char **dest, char *src, int n, int m);
char	*ft_strnmdup(char const *src, int n, int m);
void	print_args(char **args, int size);
void	print(t_list *list, char *msg);
bool	builtin_cmd(char *cmd);

/**
 * TO DO
 * norminette
 * Error: TOO_MANY_FUNCS       (line:  91, col:   1):	Too many functions in file
*/

/**
 * Implementaion in srcs/validate/validate.c
*/
int		input_validate(char **input);

/**
 * Implementaion in srcs/validate/quote.c
*/
int		ft_isquote(int c);
int		ft_skip_quoted(char *token, int *index);
char	*remove_quotes(char *str);
char	*enclosed_in_quotes(char *input);
bool	ft_isquoted(const char *str, int n);

/**
 * Implementaion in srcs/validate/check_pipe.c
*/
int		check_pipe_character(char *input);

/**
 * Implementaion in srcs/validate/check_output.c
*/
int		check_output_character(char *input);

/**
 * Implementaion in srcs/validate/check_input.c
*/
int		check_input_character(char *input);

/**
 * -----> cleared up to this point
*/



t_env	*init_env(char **envp);
void init_cmd(t_cmd *cmd);


//char 	*in_quotes(char *input);


/**
 * Implementation in srcs/token
*/
t_list	*list_add_back(t_list *list, char *str);
t_cmd	*list_add_command(t_cmd *cmds, t_cmd *node);
int		extract_tokens(t_list **tokens, char *input);

/**
 * Implementation in srcs/parser
*/
int		parse_and_expand(t_shell *mini);
t_cmd	*handel_simpel(t_shell *mini, t_list *current);
char *handle_dollar(t_shell *mini, char *token);
t_cmd *handel_output(t_shell *mini, char *token);
t_cmd *handel_input(t_shell *mini, char *token);
t_cmd *handle_heredoc(t_shell *mini, t_cmd *cmd, char *token);
bool in_single_quotes(const char *str, int index);
char	*ft_extract_word(char *token, int *index);
int		ft_isquote(int c);
int		ft_skip_quoted(char *token, int *index);
int		get_num_args(char *token);
char **set_arg_array(char *token, int size);
int ft_isquote(int c);
char *ft_getenv(t_shell *mini, char *name);

/**
 * Implementaion in srcs/execute.c
*/
int execute(t_shell *mini);

/**
 * Implementaion in srcs/cleaner.c
*/
int clear_and_exit(t_shell *mini);
void print_cmd(t_cmd *cmd);

/**
 * Implementaion in srcs/signal.c
*/
void init_sig(void);

/**
 * Implementaion in srcs/redirect.c
*/
char *set_filename(char *token, int ch);
char *set_filename(char *token, int ch);
char *set_arg_string(char *token, int ch);
char *get_arg_string(char *token);
int set_command_type(char *token);


/**
 * Implementaion in srcs/heredoc.c
*/


/**
 * Implementaion in srcs/buit_in
*/
int		builtin_unset(t_shell *mini, char **unset_args);
int		builtin_exit(t_shell *mini);
int		builtin_pwd(void);
int		builtin_cd(t_shell *mini);
int		builtin_env(t_shell *mini);


bool is_char_in_quotes(const char *str, char c);


t_env	*new_node(char *content);
void	add_to_list(t_env **env, char *content);
void	list_env(t_env **env, char **envp);
char	**copy_env(t_env *env);
//char	*extract_env_value(t_initenv *initenv, char *name);

int		check_builtin(t_shell *mini);
int		ft_arraylen(char **envp);
char 	*get_commando(char *token);
int		tokenize(t_shell *mini, char *input);


t_cmd *handle_quoted(t_shell *mini, char *token);
char *enclosed_in_quotes(char *input);
int check_if_quoted(char *input);
char *remove_quotes(char *str);
char *set_path(t_shell *mini, char *token);
int get_num_args(char *token);
//char **set_arg_array(int num_args, char *token, char *cmdpath);
#endif
