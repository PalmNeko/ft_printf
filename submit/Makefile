# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:10:34 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/24 16:59:46 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# overview
NAME = libftprintf.a

# libraries
LIBFT = Libft/libft.a

# compile settings
CC = cc
CFLAGS += -g -O0 -Wall -Werror -Wextra -I Libft -I .
SRCS += \
	./features/ft_printf.c \
	./features/ft_vdprintf.c \
	./modules/fp_gen_intstr.c \
	./modules/fp_ptr2str.c \
	./modules/free_t_cs.c \
	./modules/generate_cs.c \
	./modules/get_cs_len.c \
	./modules/is_conversion_specifier.c \
	./modules/is_flag.c \
	./modules/is_set_zero_precision.c \
	./modules/new_t_cs.c \
	./modules/fp_print_aligned_left.c \
	./modules/fp_print_aligned_right.c \
	./modules/fp_add_sign.c \
	./modules/fp_pad_for_num.c \
	./modules/fp_int2str.c \
	./modules/fp_to_upper.c \
	./modules/fp_uint2str.c \
	./modules/fp_uchr2str.c \
	./modules/fp_vdprint_cs.c \
	./modules/fp_cut_string.c \
	./modules/fp_gen_chrstr.c \
	./modules/fp_gen_ptrstr.c \
	./modules/fp_add_0x.c \
	./modules/fp_rewrite_special_behavior.c \
	./modules/fp_gen_uintstr.c \
	./modules/fp_gen_str.c

OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)

# all
all: $(NAME)

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

# make files
$(NAME): $(LIBFT) $(OBJS)
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(filter %.o, $^)

bonus: $(NAME)

$(LIBFT):
	"$(MAKE)" --directory Libft

clean:
	"$(MAKE)" --directory Libft clean
	$(RM) $(OBJS) $(DEPENDS)
	$(RM) $(OBJS_BONUS) $(DEPENDS_BONUS)
	$(RM) *.bak
	$(RM) **/*.bak
	$(RM) *.log
	$(RM) **/*.log
	$(RM) printf.log
	$(RM) ft_printf.log
	$(RM) main.d test.d

fclean: clean
	"$(MAKE)" --directory Libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) test

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -l ftprintf -o $@

check: test
	./test printf | cat -e > printf.log
	./test ft_printf | cat -e > ft_printf.log
	diff printf.log ft_printf.log

SUBMIT_REPO=git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-fc6c767f-f126-4087-9c2f-460ed6ac803e-5512429-tookuyam
submit:
	@ echo "\033[35mgenerate tmp repository for submission\033[m"
	test -d .git || git init .
	git add .
	git commit -m "submit: $(NAME)" --allow-empty > last_submit_commit.log 2>&1
	git remote show origin 2> /dev/null || git remote add origin $(SUBMIT_REPO)
	@ echo "\033[35mstatrt submit\033[m"
	git push -f origin master 2> /dev/null && echo "\033[32msuccess submit\033[m"
	@ echo "\033[33mdelete tmp repository\033[m"
	rm -rf .git
	@ echo "\033[35mtest submission\033[m"
	git clone $(SUBMIT_REPO) tmp
	make check --directory tmp > /dev/null
	@ echo "\033[32mOK!\033[m"
	rm -rf tmp
	@ echo "\033[32msucceeded\033[m"

clone_printfTester:
	git clone https://github.com/Tripouille/printfTester.git

re: fclean all

.PHONY: all clean fclean check submit clone_printfTester re
