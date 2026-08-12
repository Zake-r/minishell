NAME		=	minishell

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

INCDIR		=	./inc
LIBFTDIR	=	./libft
SRCDIR		=	./src
OBJDIR		=	./obj

INCLUDES	=	-I$(INCDIR) -I$(LIBFTDIR) -I$(LIBFTDIR)/inc

SRCS		=	$(SRCDIR)/main.c \
				$(SRCDIR)/ast/ast.c \
				$(SRCDIR)/ast/ast_utils.c \
				$(SRCDIR)/builtin/builtin_cd.c \
				$(SRCDIR)/builtin/builtin_export.c \
				$(SRCDIR)/builtin/builtin_simple.c \
				$(SRCDIR)/builtin/env_modify.c \
				$(SRCDIR)/builtin/env_utils.c \
				$(SRCDIR)/execution/exec_ast.c \
				$(SRCDIR)/execution/exec_cmd.c \
				$(SRCDIR)/execution/exec_heredoc.c \
				$(SRCDIR)/execution/exec_pipe.c \
				$(SRCDIR)/execution/exec_redirection.c \
				$(SRCDIR)/execution/redirection_utils.c \
				$(SRCDIR)/execution/search_in_path.c \
				$(SRCDIR)/parsing/free_utils.c \
				$(SRCDIR)/parsing/lexer.c \
				$(SRCDIR)/parsing/lexer_utils.c \
				$(SRCDIR)/parsing/parsing.c \
				$(SRCDIR)/parsing/parsing_env.c \
				$(SRCDIR)/parsing/parsing_quotes.c \
				$(SRCDIR)/parsing/parsing_utils.c \
				$(SRCDIR)/parsing/syntax.c \
				$(SRCDIR)/signal/handle_signal.c

OBJS		=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT		=	$(LIBFTDIR)/libft.a

LDFLAGS		=	-L$(LIBFTDIR) -lft -lreadline

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/minishell.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re