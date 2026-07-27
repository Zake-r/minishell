# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

# =========================
# Name
# =========================

NAME		= minishell

# =========================
# Compilation
# =========================

CC			= cc

CFLAGS		= -g -Wall -Wextra -Werror
READLINE	= -lreadline
IFLAGS		= -I$(INC_DIR) -I. -I$(LIBFT_DIR)

# =========================
# Libft
# =========================

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

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
all: $(LIBFT) $(NAME)

# Libft make rule:
$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

# Name rule:
$(NAME): $(OBJS) $(LIBFT)
	@echo "Compilation $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(READLINE) $(LIBFT) -o $(NAME)
	@echo "Compilation complete !"

# Compilation ".o" files:
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "Compilation $@..."
	@$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

# =========================
# Cleaning
# =========================

# Cleaning of objects:
clean_local:
	@echo "Deleting object files..."
	@rm -rf $(OBJ_DIR)

# Libft cleanup:
clean: clean_local
ifeq ($(SKIP_LIBFT_CLEAN),)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
endif

# Thorough cleaning:
fclean: SKIP_LIBFT_CLEAN=1
fclean: clean_local
	@echo "Deleting executables..."
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

# Rebuild:
re: fclean all

# =========================
# Dependencies
# =========================

-include $(DEPS)

# =========================
# Phony
# =========================

.PHONY: all clean clean_local fclean re
