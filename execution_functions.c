
#include "minishell.h"

void free_one_ast_node(t_ast *ast)
{
    int i;
    i = 0;

    if (ast->args)
    {
        while (ast->args[i])
        {
            free(ast->args[i]);
            i++;
        }
        free(ast->args);
    }
    free(ast);
}

void free_ast(t_ast *ast)
{
    if (!ast)
        return ;
    free_ast(ast->right);
    free_ast(ast->left);
    free_one_ast_node(ast);
}


void exec_cmd(t_ast *ast, char **env)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("erreur fork");
        free_ast(ast);
        return ;
    }
    if (pid == 0)
    {
        execve(ast->args[0], ast->args, env);
        perror("erreur execve");
        free_ast(ast);
        exit(1);
    }
    waitpid(pid,NULL,0);

}

void exec_pipe(t_ast *ast, char **env)
{
    pid_t pid_l;
    pid_t pid_r;
    int fd[2];

    pipe(fd);

    pid_l = fork();
    if (pid_l == -1)
    {
        perror("erreur fork");
        free_ast(ast);
        return ; 
    }
    if (pid_l == 0)
    {
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        close(fd[1]);
        exec_ast(ast->left,env);
        free_ast(ast);
        exit(0);
    }

    pid_r = fork();
    if (pid_r == -1)
    {
        perror("erreur fork");
        free_ast(ast);
        return ;
    }
    if (pid_r == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        exec_ast(ast->right,env);
        free_ast(ast);
        exit(0);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid_l,NULL,0);
    waitpid(pid_r,NULL,0);

}

void exec_redirout(t_ast *ast, char **env)
{
    int fd;
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("erreur fork");
        free_ast(ast);
        return ;
    }
    if (pid == 0)
    {
        fd = open(ast->args[0], O_WRONLY);
        if (fd == -1)
        {
            perror("erreur fd redirection\n");
            free_ast(ast);
            exit(1);
        }
        dup2(fd,STDOUT_FILENO);
        close(fd);
        exec_ast(ast->left, env);
        free_ast(ast);
        exit(1);
    }
    waitpid(pid, NULL, 0);
}


void exec_ast(t_ast *ast, char **env)
{
    if (!ast)
        return ;
    else if (ast->type == CMD)
        exec_cmd(ast, env);
    else if (ast->type == PIPE) 
        exec_pipe(ast, env); 
    else if (ast->type == REDIR_OUT) 
        exec_redirout(ast, env);
              
}

int main(int argc, char **argv, char **env)
{
    t_ast *ast;
    
    ast = create_ast(5);   
    exec_ast(ast, env);

   
    free_ast(ast);
}






