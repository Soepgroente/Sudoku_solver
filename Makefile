NAME	= sudoku_solver
SRCS	= methods.c sudoku.c utilities.c vision.c
RM		= rm -rf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address
OBJS	= $(SRCS:.c=.o)


all:	$(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:	
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
