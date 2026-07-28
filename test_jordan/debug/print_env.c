void	print_env(char **parsed_env)
{
	int i = 0;

	while (*parsed_env[i])
	{
		if (!parsed_env[i])
			return ;
		printf("%s\n", parsed_env[i]);
		i++;
	}
}
