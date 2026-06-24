
#include "minishell.h"


int main(void)
{
    t_ast ast;
    ast.type = CMD;
    ast.left = NULL;
    ast.right = NULL;

    char *args[] = {"/bin/ls","-la",NULL};
    ast.args = args;

    


}






