# tool macros
CC = cc
CFLAGS = -Wall -Werror -Wextra

# path macros
OBJ_PATH = obj
SRC_PATH = src
PATH_LIBFT = ./lib/libft
PATH_LIBFTLIB = $(PATH_LIBFT)/libft.a

# compile macros
NAME = pipex

FILES = pipex \
		handle_errors \
		handle_free \
		handle_paths \
		init	\
		parsing_commands \
		validates \
		handle_process 

OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(FILES)))

INCLUDE = -I ./inc

$(NAME): $(PATH_LIBFTLIB) $(OBJ) 
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(PATH_LIBFTLIB)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c* | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(PATH_LIBFTLIB):
	$(MAKE)	-C $(PATH_LIBFT)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

all: $(NAME)

clean:
	@$(MAKE) -C $(PATH_LIBFT) clean
	@rm -fr $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C $(PATH_LIBFT) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus