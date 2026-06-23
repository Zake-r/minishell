#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **ag, char **env)
{

	int fd[2];
	pid_t pid1;
	pid_t pid2;

	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		char *argv[] = {"/bin/ls", "-la",NULL};
		execve("/bin/ls", argv, env);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		char *argv[] = {"/usr/bin/wc", "-l",NULL};
		execve("/usr/bin/wc", argv, env);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
	return (0);
}