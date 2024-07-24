/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_uint2str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:03:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 16:43:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fp_module.h"

static char	*get_base_str(int base);

char	*fp_uint2str(int precision, int *len, unsigned long value, int base)
{
	char	*numstr;
	char	*pad_num;
	size_t	num_len;

	*len = 0;
	if (precision == 0 && value == 0)
		return (ft_strdup(""));

	numstr = ft_ultoa_base_str(value, get_base_str(base));
	if (numstr == NULL)
		return (NULL);
	num_len = ft_strlen(numstr);
	if (precision > (int)num_len)
		*len = precision;
	else
		*len = num_len;
	pad_num = fp_pad_for_num(precision, len, numstr);
	return (pad_num);
}

static char	*get_base_str(int base)
{
	if (base == 10)
		return ("0123456789");
	else if (base == 16)
		return ("0123456789abcdef");
	else
		return ("");
}
