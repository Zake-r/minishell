
SRC = minishell2.c
OBJ = $(SRC:.c=.o)
LIB_READLINE = -lreadline
EXEC = minishell

all:
	cc $(SRC) $(LIB_READLINE) -o $(EXEC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)



