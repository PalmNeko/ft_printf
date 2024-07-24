/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:11:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 15:11:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fp_module.h"

char	*fp_gen_str(t_cs *cs, int *len, char *str)
{
	int		cut_size;

	cut_size = INT_MAX;
	if (cs->is_specified_precision == true)
		cut_size = cs->precision;
	str = fp_cut_string(cut_size, len, ft_strdup(str));
	return (str);
}
