/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_ptr2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:18:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 15:27:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include "libft.h"

char	*fp_ptr2str(int precision, int *len, unsigned int value)
{
	if (value == 0)
	{
		*len = 5;
		return (ft_strdup("(nil)"));
	}
	return (fp_uint2str(precision, len, value, 16));
}
