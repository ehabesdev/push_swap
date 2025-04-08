CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = push_swap
CHECKER_NAME = checker

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib
BONUS_DIR = bonus

# Libft
LIBFT_NAME = libft
LIBFT_DIR = $(LIB_DIR)/$(LIBFT_NAME)
LIBFT_A = $(LIBFT_DIR)/$(LIBFT_NAME).a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

# ft_printf
PRINTF_NAME = ft_printf
PRINTF_DIR = $(LIB_DIR)/$(PRINTF_NAME)
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
PRINTF_MAKE = $(MAKE) -C $(PRINTF_DIR)

# Get Next Line
GNL_DIR = $(BONUS_DIR)/lib/get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(patsubst $(GNL_DIR)/%.c,$(OBJ_DIR)/%.o,$(GNL_SRCS))

COMMON_SRCS = $(SRC_DIR)/stack_utils.c \
              $(SRC_DIR)/error_utils.c \
              $(SRC_DIR)/validation_utils.c \
              $(SRC_DIR)/duplicate_utils.c \
              $(SRC_DIR)/parser.c \
              $(SRC_DIR)/operations_swap.c \
              $(SRC_DIR)/operations_push.c \
              $(SRC_DIR)/operations_rotate.c \
              $(SRC_DIR)/operations_reverse_rotate.c \
              $(SRC_DIR)/sort_utils.c

PS_ONLY_SRCS = $(SRC_DIR)/push_swap.c \
               $(SRC_DIR)/sorting_algo.c \
               $(SRC_DIR)/indexing_utils.c

CHECKER_SRCS = $(BONUS_DIR)/src/checker.c $(BONUS_DIR)/src/checker_utils.c

COMMON_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(COMMON_SRCS))
PS_ONLY_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(PS_ONLY_SRCS))
CHECKER_OBJS = $(patsubst $(BONUS_DIR)/src/%.c,$(OBJ_DIR)/%.o,$(CHECKER_SRCS))

INCLUDES = -I$(INC_DIR) \
           -I$(LIBFT_DIR) \
           -I$(PRINTF_DIR) \
           -I$(BONUS_DIR)/include \
           -I$(GNL_DIR)

all: $(NAME)

$(NAME): $(PS_ONLY_OBJS) $(COMMON_OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(PS_ONLY_OBJS) $(COMMON_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS) $(COMMON_OBJS) $(GNL_OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(COMMON_OBJS) $(GNL_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(CHECKER_NAME)

$(LIBFT_A):
	$(LIBFT_MAKE) all
       
$(PRINTF_A):
	$(PRINTF_MAKE) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/src/%.c $(BONUS_DIR)/include/checker.h $(INC_DIR)/push_swap.h Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c $(GNL_DIR)/get_next_line.h Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(LIBFT_MAKE) clean
	$(PRINTF_MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER_NAME)
	$(LIBFT_MAKE) fclean
	$(PRINTF_MAKE) fclean

re: fclean all

reb: fclean bonus all

.PHONY: all clean fclean re bonus reb
