/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_add_0x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:52:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 16:18:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "libft.h"

char	*fp_add_0x(bool be_add, int	*len, char *str)
{
	char	*added;

	if (str == NULL || *len > INT_MAX - 2)
		return (NULL);
	if (be_add == false)
		return (str);
	if (ft_isdigit(str[0]) == false)
		return (str);
	added = ft_strjoin("0x", str);
	free(str);
	*len += 2;
	return (added);
}
