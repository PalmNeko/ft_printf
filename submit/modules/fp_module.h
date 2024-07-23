/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_module.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:11:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 15:57:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_MODULE_H
# define FP_MODULE_H

int		fp_print_aligned_left(int fd, int field_width, int *len, char *str);
int		fp_print_aligned_right(int fd, int field_width, int *len, char *str);
int		fp_vdprint_cs(int fd, t_cs *cs, va_list args);
char	*fp_add_sign(int type, int *len, char *str);
char	*fp_pad_for_num(int zero_field_width, int *size, char *str);
char	*fp_int2str(int precision, int *len, int value);
char	*fp_add_0x(bool be_add, int	*len, char *str);
char	*fp_uint2str(int precision, int *len, unsigned int value, int base);
char	*fp_cut_string(int length, int *size, char *str);
char	*fp_to_upper(bool be_upper, int *len, char *str);
char	*fp_uchr2str(int *size, unsigned char chr);

#endif
