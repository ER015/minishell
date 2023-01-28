NAME	=	minishell

CC		=	gcc

FLAGS	=	 -I.

LFLAGS	=	-lreadline

SRC		=	$(wildcard ./*.c)

OBJ		=	$(patsubst %.c, %.o, $(SRC))

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) $(LFLAGS) -o $(NAME) $(OBJ)
			@echo "- COMPILED -\n"

exe:		all
			@./$(NAME)
			@echo "- DONE -\n"

clean:
			@echo "- REMOVING -\n"
			@rm -rf $(OBJ)

fclean:		clean
			@echo "- REMOVING $(NAME) -\n"
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re exe