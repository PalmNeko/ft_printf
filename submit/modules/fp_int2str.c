/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_int2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:37:05 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 16:37:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fp_module.h"

char	*fp_int2str(int precision, int *len, int value)
{
	char	*numstr;
	char	*pad_num;
	size_t	num_len;

	*len = 0;
	if (precision == 0 && value == 0)
		return (ft_strdup(""));
	numstr = ft_itoa(value);
	if (numstr == NULL)
		return (NULL);
	num_len = ft_strlen(numstr);
	if (precision > (int)num_len)
		*len = precision;
	else
		*len = num_len;
	if (numstr[0] == '-')
	{
		pad_num = fp_pad_for_num(precision + 1, len, numstr);
		*len += 1;
	}
	else
		pad_num = fp_pad_for_num(precision, len, numstr);
	return (pad_num);
}
