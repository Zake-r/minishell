#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
// ls | wc -l
int main(void)
{
    int     fd[2];

	pipe(fd);
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        // enfant 1 : exécute "ls"
        // ??? brancher stdout vers le pipe
        // ??? fermer les fd inutiles
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
        char *args[] = {"/bin/ls", NULL};
        execve("/bin/ls", args, NULL);
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        // enfant 2 : exécute "wc -l"
        // ??? brancher stdin depuis le pipe
        // ??? fermer les fd inutiles
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
        char *args[] = {"/usr/bin/wc", "-l", NULL};
        execve("/usr/bin/wc", args, NULL);
    }

    // ??? fermer les fd dans le parent
	close(fd[1]);
	close(fd[0]);
    // ??? attendre les deux enfants
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
    return (0);
}