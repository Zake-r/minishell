#include "minishell.h"

int count_word(char *s)
{
	int count = 0;
	while (*s)
	{
		while (*s == ' ' && *s != '\0')
			s++;
		if (*s != ' ' && *s != '\0')
			count++;
		while (*s != ' ' && *s != '\0')
			s++;

	}
	return (count);

}

int count_pipe(char *s)
{
	int count = 0;
	while (*s)
	{
		if (*s == '|')
			count++;
		s++;
	}
	return (count);

}

int count_word_to_pipe(char *s)
{
	int count = 0;
	while (*s && *s != '|')
	{
		while (*s == ' ' && *s != '\0' && *s != '|')
			s++;
		if (*s != ' ' && *s != '\0' && *s != '|')
			count++;
		while (*s != ' ' && *s != '\0' && *s != '|')
			s++;
	}
	return (count);
}

int main(int argc, char **argv, char **env)
{
	pid_t pid1;
	int nb_command = 0;
	
	char *line = readline(">");
	char ***tab;
	tab = malloc(sizeof(t_token) * (count_pipe(line) + 1));
	while ()

	pid1 = fork();
	if (pid1 == 0)
	{
		execve(argv[1], argv + 1, env);
		printf("wrong command\n");
		return (1);
	}
	else if (pid1 > 0)
		printf("this is parent process\n");
	waitpid(pid1,NULL,0);
	printf("end program\n");
}
