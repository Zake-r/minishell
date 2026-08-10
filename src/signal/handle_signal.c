#include "../../inc/minishell.h"

void handle_ctrlc(int num)
{
	(void)num;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	
}

void handle_ctrlc_heredoc(int num)
{
	(void)num;
	rl_replace_line("", 0);
	exit(0);
}
