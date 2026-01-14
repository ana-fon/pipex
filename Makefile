
BUILD_DIR = .build

# Executável
NAME = pipex

# Sources
FILES = main.c utils.c free.c ft_split.c ft_strjoin.c ft_strnstr.c \
			ft_strlen.c
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, $(FILES))
OBJS = $(SRC:$(SRC_PATH)/%.c=$(BUILD_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# MAIN RULE
all: $(NAME)

# COMPILE OBJS
$(BUILD_DIR)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $< -o $@

# COMPILE EXE
$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Limpeza de objetos
clean:
	rm -fr $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

# Recompilar do zero
re: fclean all
