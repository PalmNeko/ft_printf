/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:36:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/22 13:35:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "_ft_vdprint_cs.h"

int	ft_vdprint_cs(int fd, t_cs *cs, va_list args)
{
	if (cs->conversion_specifier == CS_LOWER_S)
		return (ft_vdprint_string_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_LOWER_P)
		return (ft_vdprint_pointer_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_LOWER_C)
		return (ft_vdprint_char_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_LOWER_D)
		return (ft_vdprint_decimal_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_LOWER_U)
		return (ft_vdprint_uint_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_LOWER_I)
		return (ft_vdprint_int_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_LOWER_X)
		return (ft_vdprint_hex_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_UPPER_X)
		return (ft_vdprint_hex_upper_cs(fd, cs, args));
	else if (cs->conversion_specifier == CS_PERCENT)
		return (ft_vdprint_percent_cs(fd, cs, args));
	return (-1);
}
