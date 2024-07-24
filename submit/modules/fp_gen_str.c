/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:11:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 16:42:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "fp_module.h"
#include "libft.h"

char	*fp_gen_str(t_cs *cs, int *len, char *str)
{
	size_t	size;

	if (str == NULL)
	{
		if (cs->is_specified_precision && cs->precision < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(str);
	if (cs->is_specified_precision == true)
		str = fp_cut_string(cs->precision, len, str);
	size = ft_strnlen(str, (size_t)INT_MAX + 1);
	if (size > INT_MAX)
		return (free(str), NULL);
	*len = size;
	return (str);
}
