/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:20:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 12:15:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fp.h"
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
