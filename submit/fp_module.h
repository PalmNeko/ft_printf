/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_module.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:11:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 13:36:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_MODULE_H
# define FP_MODULE_H

# include <stdbool.h>
# include <stdarg.h>
# include "fp_module_types.h"

int		fp_print_aligned_left(int fd, int field_width, int *len, char *str);
int		fp_print_aligned_right(int fd, int field_width, int *len, char *str);
int		fp_vdprint_cs(int fd, t_cs *cs, va_list args);
char	*fp_add_sign(int type, int *len, char *str);
char	*fp_pad_for_num(int zero_field_width, int *size, char *str);
char	*fp_convert_int2str(int precision, int *len, int value);
char	*fp_add_0x(bool be_add, int	*len, char *str);
char	*fp_convert_uint2str(int precision, int *len, unsigned long value, int base);
char	*fp_cut_string(int length, int *size, char *str);
char	*fp_to_upper(bool be_upper, int *len, char *str);
char	*fp_convert_uchr2str(int *size, unsigned char chr);
t_cs	*new_t_cs(void);
t_cs	*generate_cs(const char *format);
int		get_cs_len(const char *format);
void	free_t_cs(t_cs *ptr);
void	fp_rewrite_special_behavior(t_cs *cs);
bool	is_flags(char c);
bool	is_conversion_specifier(char c);
bool	is_set_zero_precision(t_cs *cs);
char	*fp_gen_str(t_cs *cs, int *len, char *str);
char	*fp_gen_chrstr(t_cs *cs, int *len, unsigned char uchr);
char	*fp_gen_uintstr(t_cs *cs, int *len, unsigned long value, int base);
char	*fp_gen_intstr(t_cs *cs, int *len, int value);
char	*fp_convert_ptr2str(int precision, int *len, unsigned int value);
char	*fp_gen_ptrstr(t_cs *cs, int *len, unsigned long value);

#endif
