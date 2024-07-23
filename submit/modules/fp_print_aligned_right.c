/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_print_aligned_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:20:09 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 14:12:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include "libft.h"

int	fp_print_aligned_right(int fd, int field_width, int *len, char *str)
{
	ssize_t	write_len;

	if (str == NULL)
		return (-1);
	write_len = ft_write_aligned_right(fd, str, *len, field_width);
	if (write_len < 0 || INT_MAX < write_len)
		return (free(str), -1);
	return ((int)write_len);
}
