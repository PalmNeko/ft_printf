/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_ptrstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 16:27:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include "libft.h"

char	*fp_gen_ptrstr(t_cs *cs, int *len, unsigned int value)
{
	int	sign_type;

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
	return (fp_add_sign(sign_type, len, fp_gen_uintstr(cs, len, value, 16)));
}
