/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_gen_ptrstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/24 15:25:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp_module.h"

char	*fp_gen_ptrstr(t_cs *cs, int *len, unsigned int value)
{
	return (fp_ptr2str(cs->precision, len, value));
}
