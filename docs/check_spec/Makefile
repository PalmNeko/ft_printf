NAME        = check_spec
SRCS        = check_spec.c
OBJS        = $(SRCS:.c=.o)
DEPS        = $(SRCS:.c=.d)
CC          = cc
CFLAGS      = -g -O0 -Wall -Wextra -Werror -MP -MMD -I libft
LDFLAGS     = -Llibft
LDLIBS		= -lft

.PHONY: all
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

Libft:
	git clone git@github.com:PalmNeko/Libft.git libft
	cd libft && make

-include $(DEPS)
