/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_vdprint_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:20:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 16:26:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "fp_module.h"

char	*fp_gen_vdprint_cs(t_cs *cs, int *len, va_list args);

int	fp_vdprint_cs(int fd, t_cs *cs, va_list args)
{
	char	*out_string;
	int		len;

	len = 0;
	out_string = NULL;
	if (cs->conversion_specifier == CS_PERCENT)
		return (write(fd, "%", 1));
	out_string = fp_gen_vdprint_cs(cs, &len, args);
	if (out_string == NULL)
		return (-1);
	if (cs->flag_minus)
		return (fp_print_aligned_left(fd, cs->minimum_field_width, &len, out_string));
	else
		return (fp_print_aligned_right(fd, cs->minimum_field_width, &len, out_string));
}

char	*fp_gen_vdprint_cs(t_cs *cs, int *len, va_list args)
{
	char	*out_string;

	out_string = NULL;
	if (cs->conversion_specifier == CS_LOWER_D
		|| cs->conversion_specifier == CS_LOWER_I)
		out_string = fp_gen_intstr(cs, len, va_arg(args, int));
	else if (cs->conversion_specifier == CS_LOWER_S)
		out_string = fp_gen_str(cs, len, va_arg(args, char *));
	else if (cs->conversion_specifier == CS_LOWER_C)
		out_string = fp_gen_chrstr(cs, len, (unsigned char)va_arg(args, int));
	else if (cs->conversion_specifier == CS_LOWER_X
		|| cs->conversion_specifier == CS_UPPER_X)
		out_string = fp_gen_uintstr(cs, len, va_arg(args, unsigned int), 16);
	else if (cs->conversion_specifier == CS_LOWER_U)
		out_string = fp_gen_uintstr(cs, len, va_arg(args, unsigned int), 10);
	else if (cs->conversion_specifier == CS_LOWER_P)
		out_string = fp_gen_ptrstr(cs, len, va_arg(args, unsigned int));
	return (out_string);
}
