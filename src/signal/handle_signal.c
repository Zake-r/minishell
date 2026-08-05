#include "../../inc/minishell.h"

void handle_ctr(int num)
{
	(void)num;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}