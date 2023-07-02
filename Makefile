NAME	= sudoku_solver
RM		= rm -rf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address
SRCS	= methods.c sudoku.c utilities.c vision.c

OBJDIR	= Sudobjects

OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)

all:	$(NAME)

$(OBJDIR)/%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:	
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
