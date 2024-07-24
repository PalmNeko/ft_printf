/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_uintstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:08:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 15:09:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"

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
