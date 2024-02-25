# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:08 by tookuyam          #+#    #+#              #
#    Updated: 2023/11/09 13:20:26 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
SRC_PATH = "./docs/*" "./sample_printf/*"
SRCS += $(shell find tests -name "*.c")
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)
INC_DIRS = $(dir $(shell find . -type f -name "*.h"))
CFLAGS += $(addprefix -I, $(INC_DIRS))
LIBS_TYCTEST = ./libs/libtyctest_main.a ./libs/libtyctest.a
LIB_FT_PRINTF = submit/libftprintf.a
LIB_FT = submit/Libft/libft.a
all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS) $(LIBS_TYCTEST) $(LIB_FT_PRINTF) $(LIB_FT)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(LIB_FT_PRINTF):
	$(MAKE) --directory submit

$(LIB_FT): submit/Libft
	$(MAKE) --directory submit/Libft

submit/Libft:
	bash install_dep.sh

check: $(NAME)
	./$(NAME)
	cd submit
	francinette -mb

clean:
	$(RM) $(OBJS) $(DEPENDS)
	$(MAKE) --directory submit clean
	$(MAKE) --directory submit/Libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) --directory submit fclean
	$(MAKE) --directory submit/Libft fclean

re: fclean all

.PHONY: all clean fclean re
