/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:20:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/22 14:38:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*format;
	int		result;

	format = "%s\n";
	printf("output: \"");
	fflush(stdout);
	result = printf(format, NULL);
	printf("\"\n");
	printf("result: %d\n", result);
}
