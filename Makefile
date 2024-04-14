CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
SRC = src/pipex.c
DIR = libft
NAME = pipex

all: prog

$(DIR)/libft.a:
	@echo "Compiling libft...\n"
	@$(MAKE) -C $(DIR) -s all
	

prog: $(NAME)
	@echo "Your $(NAME) program is ready :)\n"

$(NAME): $(DIR)/libft.a $(SRC) src/pipex_utils.c src/err.c
	@echo "Compiling $(NAME)...\n"
	@$(CC) $(CFLAGS) $(SRC) src/pipex_utils.c src/err.c $(DIR)/libft.a -o $(NAME)

clean:
	@echo "Removing the .o files...\n"
	@$(MAKE) -C $(DIR) -s clean
	@echo "Done Removing the .o files\n"

fclean: clean
	@echo "Removing the libft.a and pipex...\n"
	@$(MAKE) -C $(DIR) -s fclean
	@$(RM) $(NAME)
	@echo "Done Removing the libft.a and $(NAME)\n"

re: fclean all