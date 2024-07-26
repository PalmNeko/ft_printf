# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:10:34 by tookuyam          #+#    #+#              #
#    Updated: 2024/07/26 15:35:57 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# overview
NAME = libftprintf.a
CC = cc
CFLAGS += -g -O0 -Wall -Werror -Wextra -MP -MMD -I Libft -I .
SRCS += \
	./ft_printf.c \
	./ft_vdprintf.c \
	./fp_modules/fp_gen_intstr.c \
	./fp_modules/fp_convert_ptr2str.c \
	./fp_modules/fp_destroy_t_cs.c \
	./fp_modules/fp_generate_cs.c \
	./fp_modules/fp_get_cs_len.c \
	./fp_modules/fp_new_t_cs.c \
	./fp_modules/fp_print_aligned_left.c \
	./fp_modules/fp_print_aligned_right.c \
	./fp_modules/fp_add_sign.c \
	./fp_modules/fp_pad_for_num.c \
	./fp_modules/fp_convert_int2str.c \
	./fp_modules/fp_to_upper.c \
	./fp_modules/fp_convert_uint2str.c \
	./fp_modules/fp_convert_uchr2str.c \
	./fp_modules/fp_vdprint_cs.c \
	./fp_modules/fp_cut_string.c \
	./fp_modules/fp_gen_chrstr.c \
	./fp_modules/fp_gen_ptrstr.c \
	./fp_modules/fp_get_sign_type.c \
	./fp_modules/fp_add_0x.c \
	./fp_modules/fp_rewrite_special_behavior.c \
	./fp_modules/fp_gen_uintstr.c \
	./fp_modules/fp_gen_str.c
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)
LIBFT = Libft/libft.a

# all
all: $(NAME)

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

re: fclean all

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -l ftprintf -o $@

.PHONY: all clean fclean re test 

-include $(DEPENDS)

$(NAME): $(LIBFT) $(OBJS)
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(filter %.o, $^)

bonus: $(NAME)

$(LIBFT): $(dir $(LIBFT))
	"$(MAKE)" --directory Libft

$(dir $(LIBFT)):
	git clone git@github.com:PalmNeko/Libft.git $@

printfTester:
	git clone https://github.com/Tripouille/printfTester.git
