/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_vdprint_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:20:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 16:30:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "fp_module.h"

char	*fp_gen_str(t_cs *cs, int *len, char *str);
char	*fp_gen_chrstr(t_cs *cs, int *len, unsigned char uchr);
char	*fp_gen_uintstr(t_cs *cs, int *len, unsigned int value);
char	*fp_gen_intstr(t_cs *cs, int *len, int value);

int	fp_vdprint_cs(int fd, t_cs *cs, va_list args)
{
	char	*out_string;
	int		len;

	len = 0;
	out_string = NULL;
	if (cs->conversion_specifier == CS_LOWER_D
		|| cs->conversion_specifier == CS_LOWER_I)
		out_string = fp_gen_intstr(cs, &len, va_arg(args, int));
	else if (cs->conversion_specifier == CS_LOWER_S)
		out_string = fp_gen_str(cs, &len, va_arg(args, char *));
	else if (cs->conversion_specifier == CS_LOWER_C)
		out_string = fp_gen_chrstr(cs, &len, (unsigned char)va_arg(args, int));
	else if (cs->conversion_specifier == CS_PERCENT)
		return (write(fd, "%", 1));
	else if (cs->conversion_specifier == CS_LOWER_X
		|| cs->conversion_specifier == CS_UPPER_X
		|| cs->conversion_specifier == CS_LOWER_U
		|| cs->conversion_specifier == CS_LOWER_P)
		out_string = fp_gen_uintstr(cs, &len, va_arg(args, unsigned int));
	if (out_string == NULL)
		return (-1);
	if (cs->flag_minus)
		return (fp_print_aligned_left(fd, cs->minimum_field_width, &len, out_string));
	else
		return (fp_print_aligned_right(fd, cs->minimum_field_width, &len, out_string));
}

char	*fp_gen_intstr(t_cs *cs, int *len, int value)
{
	char	*str;
	int		sign_type;
	int		zero_field_width;

	sign_type = 0;
	if (cs->flag_plus)
		sign_type = 1;
	else if (cs->flag_space)
		sign_type = 2;
	zero_field_width = 0;
	if (cs->flag_zero && cs->is_specified_min_field_width)
		zero_field_width = cs->minimum_field_width;
	str = fp_add_sign(sign_type, len,
			fp_pad_for_num(zero_field_width, len,
				fp_int2str(cs->precision, len, value)));
	return (str);
}

char	*fp_gen_uintstr(t_cs *cs, int *len, unsigned int value)
{
	char	*str;
	int		zero_field_width;
	int		base;

	zero_field_width = 0;
	if (cs->flag_zero && cs->is_specified_min_field_width)
		zero_field_width = cs->minimum_field_width;
	base = 10;
	if (cs->conversion_specifier == CS_UPPER_X
		|| cs->conversion_specifier == CS_LOWER_X)
		base = 16;
	str = fp_to_upper(cs->conversion_specifier == CS_UPPER_X, len,
			fp_add_0x(cs->flag_sharp, len,
				fp_pad_for_num(zero_field_width, len,
					fp_uint2str(cs->precision, len, value, base))));
	return (str);
}

char	*fp_gen_chrstr(t_cs *cs, int *len, unsigned char uchr)
{
	char	*str;

	(void)cs;
	str = fp_uchr2str(len, uchr);
	return (str);
}

char	*fp_gen_str(t_cs *cs, int *len, char *str)
{
	int		cut_size;

	cut_size = INT_MAX;
	if (cs->is_specified_precision == true)
		cut_size = cs->precision;
	str = fp_cut_string(cut_size, len, ft_strdup(str));
	return (str);
}
