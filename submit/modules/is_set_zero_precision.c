/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set_zero_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:24:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 16:16:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include <stdbool.h>

bool	is_set_zero_precision(t_cs *cs)
{
	if (cs->is_specified_precision && cs->precision == 0)
		return (true);
	else
		return (false);
}
