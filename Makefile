NAME    	= pipex
OBJ     	= $(SRC:%.c=%.o)
OBJUTILS	= $(UTILS:%.c=%.o)
OBJ_BONUS	= $(SRC_BONUS:%.c=%.o)
CFLAGS  	= -Wall -Werror -Wextra -g -IInclude #-O3
SANIFLAGS	= -fsanitize=address -g
CC 			= @gcc

SRC_BONUS	=	srcs/main_bonus.c \
				srcs/path.c \
				srcs/error.c \
				srcs/here_doc.c

SRC     	=	srcs/main.c \
				srcs/path.c \
				srcs/error.c

UTILS		=	srcs/utils/ft_split.c \
				srcs/utils/ft_str_add.c \
				srcs/utils/ft_strncmp.c \
				srcs/utils/ft_strnfind.c \
				srcs/utils/ft_strdup.c \
				srcs/utils/ft_free_matrix.c \
				srcs/utils/lst_functions.c 

all: $(NAME)

$(NAME): $(OBJUTILS) $(OBJ)
	$(CC) $(OBJUTILS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Toma la pah --> $(YELLOW)$(NAME)$(DEFAULT)"

sanitize: $(OBJUTILS) $(OBJ)
	$(CC) $(OBJUTILS) $(OBJ) $(SANIFLAGS) -o $(NAME)
	@echo "$(GREEN)Sera que tens leaks? --> $(YELLOW)$(NAME)$(DEFAULT)"

bonus:: $(OBJUTILS) $(OBJ_BONUS)
	$(CC) $(OBJUTILS) $(OBJ_BONUS) -o $(NAME)
	@echo "$(GREEN)Toma la pah --> $(YELLOW)$(NAME)$(DEFAULT)"

clean:
	@rm -f $(OBJ) $(OBJUTILS) $(OBJ_BONUS)
	@echo "$(RED)Housekeeping...$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Byeee, files removed!$(DEFAULT)"

re: fclean all


#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m