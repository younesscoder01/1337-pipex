CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -crs
RM = rm -f
SRC = src/pipex.c
DIR = libft
NAME = pipex

all: $(NAME)

$(DIR)/libft.a:
	@echo "\033[0;31mCompiling libft.a...\n"
	@$(MAKE) -C $(DIR) -s all
	@echo "\033[0;32mDone Compiling libft.a\n"

$(NAME): $(DIR)/libft.a
	@echo "\033[0;31mCompiling $(NAME)...\n"
	@cc $(SRC) $(DIR)/libft.a -o $(NAME)
	@echo "\033[0;32mYour $(NAME) program is ready is ready\n"

clean:
	@echo "\033[0;31mRemoving the .o files...\n"
	@$(MAKE) -C $(DIR) -s clean
	@echo "\033[0;32mDone Removing the .o files\n"

fclean: clean
	@echo "\033[0;31mRemoving the libft.a and pipex...\n"
	@$(MAKE) -C $(DIR) -s fclean
	@$(RM) $(NAME)
	@echo "\033[0;32mDone Removing the libft.a and $(NAME)\n"

re: fclean all