/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_ptrstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 15:05:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include "libft.h"
#include <stdlib.h>

char	*fp_gen_ptrstr(t_cs *cs, int *len, unsigned long value)
{
	int		sign_type;
	char	*tmp;
	char	*str;

	sign_type = 0;
	if (cs->flag_plus)
		sign_type = 1;
	else if (cs->flag_space)
		sign_type = 2;

	if (value == 0)
	{
		*len = 5;
		return (ft_strdup("(nil)"));
	}
	tmp = fp_gen_uintstr(cs, len, value, 16);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	tmp = fp_add_sign(sign_type, len, str);
	free(str);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	return (str);
}
