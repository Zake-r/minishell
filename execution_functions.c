
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
        return (1);
    }
    if (pid == 0)
    {
        execve(ast->args[0], ast->args, env);
        perror("erreur execve");
        exit(1);
    }
    waitpid(pid,NULL,0);

}


void execute_rec(t_ast *ast,char **env)
{
    if (!ast)
        return ;
    if (ast->type == CMD)
        exec_cmd(ast, env);
    if (ast->type == PIPE) 
        execute_rec(ast->right, env); 
        execute_rec(ast->left, env);
    



}

int main(int argc, char **argv, char **env)
{
    t_ast *ast;
    
    ast = create_ast(0);   
    execute_rec(ast, env);

   
    free_ast(ast);
}






