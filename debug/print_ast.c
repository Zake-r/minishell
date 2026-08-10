static void	print_prefix(int depth, int is_last)
{
	int	i;

	i = 0;

	while (i < depth)
	{
		printf("│   ");
		i++;
	}

	if (depth > 0)
	{
		if (is_last)
			printf("└── ");
		else
			printf("├── ");
	}
}


static char	*ast_type_name(t_type type)
{
	if (type == WORD)
		return ("WORD");
	if (type == PIPE)
		return ("PIPE");
	if (type == REDIR_IN)
		return ("REDIR_IN (<)");
	if (type == REDIR_OUT)
		return ("REDIR_OUT (>)");
	if (type == APPEND)
		return ("REDIR_APPEND (>>)");
	if (type == HEREDOC)
		return ("HEREDOC (<<)");

	return ("UNKNOWN");
}


static void	print_args(char **args, int depth)
{
	int	i;

	i = 0;

	while (args && args[i])
	{
		print_prefix(depth, 1);
		printf("- %s\n", args[i]);
		i++;
	}
}


void	print_ast(t_ast *ast, int depth, int is_last)
{
	if (!ast)
		return ;


	print_prefix(depth, is_last);
	printf("%s\n", ast_type_name(ast->type));


	/*
	** WORD
	** └── args:
	**     └── - argument
	*/
	if (ast->type == WORD && ast->args)
	{
		print_prefix(depth + 1, 1);
		printf("args:\n");

		print_args(ast->args, depth + 2);
	}


	/*
	** LEFT
	** ├── left
	*/
	if (ast->left)
	{
		print_prefix(depth + 1, 0);
		printf("left\n");

		print_ast(ast->left, depth + 2, 1);
	}


	/*
	** RIGHT
	** └── right
	*/
	if (ast->right)
	{
		print_prefix(depth + 1, 1);
		printf("right\n");

		print_ast(ast->right, depth + 2, 1);
	}
	printf("\n");
}