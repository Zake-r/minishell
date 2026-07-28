# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

# =========================
# Name
# =========================

NAME		= libft.a

# =========================
# Compilation
# =========================

CC			= cc

CFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR) -I.

# =========================
# Directories
# =========================

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= inc/

# =========================
# Files
# =========================

SRCS		= $(shell find $(SRC_DIR) -name "*.c")

OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

DEPS		= $(OBJS:.o=.d)

# =========================
# Rules
# =========================

# Main rule:
all: $(NAME)

# Lib creation:
$(NAME): $(OBJS)
	@echo "Compilation Libft..."
	@ar rcs $(NAME) $(OBJS)
	@echo "Libft created !"

# Compilation ".o" files:
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "Compilation $@..."
	@$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

# =========================
# Cleaning
# =========================

# Cleaning of objects:
clean:
	@echo "Deleting object files libft..."
	@rm -rf $(OBJ_DIR)

# Thorough cleaning:
fclean: clean
	@echo "Deleting Libft..."
	@rm -f $(NAME)

# Rebuild:
re: fclean all

# =========================
# Dependencies
# =========================

-include $(DEPS)

# =========================
# Phony
# =========================

.PHONY: all clean fclean re
