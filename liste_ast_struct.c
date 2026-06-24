#include "minishell.h"


t_ast create_ast(int nb);
{
    if (nb == 0)
    {
        //ls -la
        t_ast ast;
        ast.type  = CMD;
        ast.left  = NULL;
        ast.right = NULL;
        char *args[] = {"/bin/ls", "-la", NULL};
        ast.args  = args;
    }

}