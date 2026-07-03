/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbusquet <jbusquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:08:26 by jbusquet          #+#    #+#             */
/*   Updated: 2026/07/02 13:08:26 by jbusquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_tokens(t_token *tokens)
{
	char	*type;

	while (tokens)
	{
		if (tokens->type == 0)
			type = "WORD";
		else if (tokens->type == 1)
			type = "PIPE";
		else if (tokens->type == 2)
			type = "REDIR_IN";
		else if (tokens->type == 3)
			type = "REDIR_OUT";
		else if (tokens->type == 4)
			type = "APPEND";
		else if (tokens->type == 5)
			type = "HEREDOC";
		printf("type -> %s=%d value=%s\n",
			type,
			tokens->type,
			tokens->value);
		tokens = tokens->next;
	}
}
