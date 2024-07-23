/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_module.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:11:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 14:13:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_MODULE_H
# define FP_MODULE_H

int	fp_print_aligned_left(int fd, int field_width, int *len, char *str);
int	fp_print_aligned_right(int fd, int field_width, int *len, char *str);

#endif
