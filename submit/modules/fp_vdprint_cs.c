/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_vdprint_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:20:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 16:54:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "fp_module.h"

char	*fp_gen_vdprint_cs(t_cs *cs, int *len, va_list args);

int	fp_vdprint_cs(int fd, t_cs *cs, va_list args)
{
	char	*out_string;
	int		len;
	int		out_len;

	len = 0;
	out_string = NULL;
	if (cs->type == CS_PERCENT)
		return (write(fd, "%", 1));
	out_string = fp_gen_vdprint_cs(cs, &len, args);
	if (out_string == NULL)
		return (-1);
	if (cs->flag_minus)
		out_len = fp_print_aligned_left(fd, cs->field_width, &len, out_string);
	else
		out_len = fp_print_aligned_right(fd, cs->field_width, &len, out_string);
	free(out_string);
	return (out_len);
}

char	*fp_gen_vdprint_cs(t_cs *cs, int *len, va_list args)
{
	char	*out_string;

	out_string = NULL;
	if (cs->type == CS_LOWER_D
		|| cs->type == CS_LOWER_I)
		out_string = fp_gen_intstr(cs, len, va_arg(args, int));
	else if (cs->type == CS_LOWER_S)
		out_string = fp_gen_str(cs, len, va_arg(args, char *));
	else if (cs->type == CS_LOWER_C)
		out_string = fp_gen_chrstr(cs, len, (unsigned char)va_arg(args, int));
	else if (cs->type == CS_LOWER_X
		|| cs->type == CS_UPPER_X)
		out_string = fp_gen_uintstr(cs, len, va_arg(args, unsigned int), 16);
	else if (cs->type == CS_LOWER_U)
		out_string = fp_gen_uintstr(cs, len, va_arg(args, unsigned int), 10);
	else if (cs->type == CS_LOWER_P)
		out_string = fp_gen_ptrstr(cs, len, va_arg(args, unsigned long));
	return (out_string);
}
