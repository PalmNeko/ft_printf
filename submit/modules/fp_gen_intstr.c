/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_intstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:09:39 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 14:37:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include <stddef.h>
#include <stdlib.h>

char	*fp_gen_intstr(t_cs *cs, int *len, int value)
{
	char	*str;
	int		sign_type;
	int		zero_field_width;
	char	*tmp;

	sign_type = 0;
	if (cs->flag_plus)
		sign_type = 1;
	else if (cs->flag_space)
		sign_type = 2;
	zero_field_width = 0;
	if (cs->flag_zero && cs->is_specified_min_field_width)
		zero_field_width = cs->minimum_field_width;
	tmp = fp_convert_int2str(cs->precision, len, value);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	tmp = fp_pad_for_num(zero_field_width, len, str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	tmp = fp_add_sign(sign_type, len, str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	return (str);
}
