# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:08 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/24 18:05:10 by tookuyam         ###   ########.fr        #
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
CFLAGS += -g -O0 $(addprefix -I, $(INC_DIRS))
LIBS_TYCTEST = ./tyctest/libtyctest_main.a ./tyctest/libtyctest.a
LIB_FT_PRINTF = submit/libftprintf.a

all: $(NAME)

-include $(DEPENDS)

$(NAME):  $(LIBS_TYCTEST) $(LIB_FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(LIB_FT_PRINTF): FORCE
	make --directory submit

FORCE:

check: $(NAME)
	./$(NAME)
	cd submit
	francinette -mb

clean:
	$(RM) $(OBJS) $(DEPENDS)
	make --directory submit clean

fclean: clean
	$(RM) $(NAME)
	make --directory submit fclean

re: fclean all

.PHONY: all clean fclean re

tyctest/libtyctest_main.a tyctest/libtyctest.a: tyctest
	make -C tyctest

tyctest:
	git clone git@github.com:PalmNeko/tyctest.git $@
