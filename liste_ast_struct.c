#include "minishell.h"

t_ast   *create_ast(int nb)
{
    t_ast   *root;
    t_ast   *left;
    t_ast   *right;
    t_ast   *pipe1;

    // ── 0 : ls -la ──────────────────────────────────────────
    if (nb == 0)
    {
        root = malloc(sizeof(t_ast));
        root->type  = CMD;
        root->left  = NULL;
        root->right = NULL;
        root->args  = malloc(sizeof(char *) * 3);
        root->args[0] = strdup("/bin/ls");
        root->args[1] = strdup("-la");
        root->args[2] = NULL;
        return (root);
    }
    // ── 1 : ls -la | grep .c ────────────────────────────────
    else if (nb == 1)
    {
        left = malloc(sizeof(t_ast));
        left->type  = CMD;
        left->left  = NULL;
        left->right = NULL;
        left->args  = malloc(sizeof(char *) * 3);
        left->args[0] = strdup("/bin/ls");
        left->args[1] = strdup("-la");
        left->args[2] = NULL;

        right = malloc(sizeof(t_ast));
        right->type  = CMD;
        right->left  = NULL;
        right->right = NULL;
        right->args  = malloc(sizeof(char *) * 3);
        right->args[0] = strdup("/bin/grep");
        right->args[1] = strdup(".c");
        right->args[2] = NULL;

        root = malloc(sizeof(t_ast));
        root->type  = PIPE;
        root->args  = NULL;
        root->left  = left;
        root->right = right;
        return (root);
    }
    // ── 2 : ls -la > output.txt ─────────────────────────────
    else if (nb == 2)
    {
        left = malloc(sizeof(t_ast));
        left->type  = CMD;
        left->left  = NULL;
        left->right = NULL;
        left->args  = malloc(sizeof(char *) * 3);
        left->args[0] = strdup("/bin/ls");
        left->args[1] = strdup("-la");
        left->args[2] = NULL;

        root = malloc(sizeof(t_ast));
        root->type  = REDIR_OUT;
        root->args  = malloc(sizeof(char *) * 2);
        root->args[0] = strdup("output.txt");
        root->args[1] = NULL;
        root->left  = left;
        root->right = NULL;
        return (root);
    }
    // ── 3 : cat file.txt | grep hello > result.txt ──────────
    else if (nb == 3)
    {
        left = malloc(sizeof(t_ast));
        left->type  = CMD;
        left->left  = NULL;
        left->right = NULL;
        left->args  = malloc(sizeof(char *) * 3);
        left->args[0] = strdup("/bin/cat");
        left->args[1] = strdup("file.txt");
        left->args[2] = NULL;

        right = malloc(sizeof(t_ast));
        right->type  = CMD;
        right->left  = NULL;
        right->right = NULL;
        right->args  = malloc(sizeof(char *) * 3);
        right->args[0] = strdup("/bin/grep");
        right->args[1] = strdup("hello");
        right->args[2] = NULL;

        pipe1 = malloc(sizeof(t_ast));
        pipe1->type  = PIPE;
        pipe1->args  = NULL;
        pipe1->left  = left;
        pipe1->right = right;

        root = malloc(sizeof(t_ast));
        root->type  = REDIR_OUT;
        root->args  = malloc(sizeof(char *) * 2);
        root->args[0] = strdup("result.txt");
        root->args[1] = NULL;
        root->left  = pipe1;
        root->right = NULL;
        return (root);
    }
    // ── 4 : cat << EOF ──────────────────────────────────────
    else if (nb == 4)
    {
        left = malloc(sizeof(t_ast));
        left->type  = CMD;
        left->left  = NULL;
        left->right = NULL;
        left->args  = malloc(sizeof(char *) * 2);
        left->args[0] = strdup("/bin/cat");
        left->args[1] = NULL;

        root = malloc(sizeof(t_ast));
        root->type  = HEREDOC;
        root->args  = malloc(sizeof(char *) * 2);
        root->args[0] = strdup("EOF");
        root->args[1] = NULL;
        root->left  = left;
        root->right = NULL;
        return (root);
    }
    // ── 5 : ps aux | grep bash | wc -l ──────────────────────
    else if (nb == 5)
    {
        left = malloc(sizeof(t_ast));
        left->type  = CMD;
        left->left  = NULL;
        left->right = NULL;
        left->args  = malloc(sizeof(char *) * 3);
        left->args[0] = strdup("/bin/ps");
        left->args[1] = strdup("aux");
        left->args[2] = NULL;

        right = malloc(sizeof(t_ast));
        right->type  = CMD;
        right->left  = NULL;
        right->right = NULL;
        right->args  = malloc(sizeof(char *) * 3);
        right->args[0] = strdup("/bin/grep");
        right->args[1] = strdup("bash");
        right->args[2] = NULL;

        pipe1 = malloc(sizeof(t_ast));
        pipe1->type  = PIPE;
        pipe1->args  = NULL;
        pipe1->left  = left;
        pipe1->right = right;

        t_ast *cmd_wc = malloc(sizeof(t_ast));
        cmd_wc->type  = CMD;
        cmd_wc->left  = NULL;
        cmd_wc->right = NULL;
        cmd_wc->args  = malloc(sizeof(char *) * 3);
        cmd_wc->args[0] = strdup("/usr/bin/wc");
        cmd_wc->args[1] = strdup("-l");
        cmd_wc->args[2] = NULL;

        root = malloc(sizeof(t_ast));
        root->type  = PIPE;
        root->args  = NULL;
        root->left  = pipe1;
        root->right = cmd_wc;
        return (root);
    }
    return (NULL);
}