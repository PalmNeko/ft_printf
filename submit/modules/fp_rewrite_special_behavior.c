/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_rewrite_special_behavior.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:24:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 16:54:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"
#include <stdio.h>

void	fp_rewrite_precision(t_cs *cs);
void	fp_rewrite_flag_zero(t_cs *cs);

void	fp_rewrite_special_behavior(t_cs *cs)
{
	if (cs->flag_minus == true)
		cs->flag_zero = false;
	if (cs->flag_plus == true)
		cs->flag_space = false;
	fp_rewrite_flag_zero(cs);
	fp_rewrite_precision(cs);
	if (cs->type != CS_LOWER_X
		&& cs->type != CS_UPPER_X
		&& cs->type != CS_LOWER_P)
		cs->flag_sharp = false;
	if (cs->type == CS_LOWER_P)
		cs->flag_sharp = true;
	return ;
}

void	fp_rewrite_precision(t_cs *cs)
{
	if (cs->is_set_precision == false
		&& (cs->type == CS_LOWER_D
			|| cs->type == CS_LOWER_I
			|| cs->type == CS_LOWER_X
			|| cs->type == CS_LOWER_P
			|| cs->type == CS_LOWER_U
			|| cs->type == CS_UPPER_X))
		cs->precision = 1;
}

void	fp_rewrite_flag_zero(t_cs *cs)
{
	if (cs->is_set_precision == true
		&& (cs->type == CS_LOWER_D
			|| cs->type == CS_LOWER_I
			|| cs->type == CS_LOWER_U
			|| cs->type == CS_LOWER_X
			|| cs->type == CS_LOWER_P
			|| cs->type == CS_UPPER_X))
		cs->flag_zero = false;
}
