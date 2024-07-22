
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

char	**generate_specifications(char cs);
char	*generate_specification(char cs, int field_width, int precision, bool flag_sharp, bool flag_minus, bool flag_plus, bool flag_zero, bool flag_space);

int main(void)
{
	const char specifications[] = {
		'\0',
		'c',
		's',
		'p',
		'd',
		'i',
		'u',
		'x',
		'X',
		'%'};
	int 	index;
	char	**specs;
	char	**top;

	printf("|%s | %s | %s|\n", "変換指定子", "値", "結果");
	printf("| -- | -- | -- |\n");
	index = 0;
	while (index < 10)
	{
		specs = generate_specifications(specifications[index]);
		if (specs == NULL)
			return (1);
		top = specs;
		while (*specs != NULL)
		{
			if (specifications[index] == '\0')
			{
				printf("|%s|\"\"|\"", *specs);
				printf(*specs, NULL);
				printf("\"|\n");
			}
			if (ft_includes(specifications[index], "s"))
			{
				char	*values[5] = {
					NULL,
					"",
					"abc",
					"  abc",
					"abc  ",
				};
				for (int i = 0; i < 5; i++)
				{
					printf("|%s|\"%s\"|\"", *specs, values[i]);
					printf(*specs, values[i]);
					printf("\"|\n");
				}
			}
			if (ft_includes(specifications[index], "di"))
			{
				long	values[11] = {
					0,
					1,
					2,
					100,
					INT_MAX,
					LONG_MAX,
					-1,
					-2,
					-100,
					INT_MIN,
					LONG_MIN,
				};
				for (int i = 0; i < 11; i++)
				{
					printf("|%s|\"%ld\"|\"", *specs, values[i]);
					printf(*specs, values[i]);
					printf("\"|\n");
				}
			}
			if (ft_includes(specifications[index], "puxX"))
			{
				unsigned long	values[8] = {
					0,
					1,
					2,
					100,
					INT_MAX,
					UINT_MAX,
					LONG_MAX,
					ULONG_MAX,
				};
				for (int i = 0; i < 8; i++)
				{
					printf("|%s|\"%lu\"|\"", *specs, values[i]);
					printf(*specs, values[i]);
					printf("\"|\n");
				}
			}
			if (ft_includes(specifications[index], "%"))
			{
				printf("|%s|\"%s\"|\"", *specs, "");
				printf(*specs, NULL);
				printf((const char *)"\"|\n");
			}
			if (ft_includes(specifications[index], "c"))
			{
				printf("|%s|\"%c\"|\"", *specs, 'a');
				printf(*specs, 'a');
				printf("\"|\n");
			}
			free(*(specs++));
		}
		free(top);
		index++;
	}
	return (0);
}

char	**generate_specifications(char cs)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	size;
	char	**specifications;
	char	*gen_ptr;

	lst = NULL;
	for (int field_width = -1; field_width < 13; field_width++) {
		for (int precision = -1; precision < 13; precision++)
			for (int sharp = 0; sharp < 2; sharp++)
				for (int minus = 0; minus < 2; minus++)
					for (int plus = 0; plus < 2; plus++)
						for (int zero = 0; zero < 2; zero++)
							for (int space = 0; space < 2; space++)
							{
								gen_ptr = generate_specification(cs, field_width, precision, sharp, minus, plus, zero, space);
								if (gen_ptr == NULL)
									return (ft_lstclear(&lst, free), NULL);
								tmp = ft_lstnew(gen_ptr);
								if (tmp == NULL)
									return (free(gen_ptr), ft_lstclear(&lst, free), NULL);
								ft_lstadd_back(&lst, tmp);
							}
	}
	tmp = ft_lstnew(NULL);
	if (tmp == NULL)
		ft_lstclear(&lst, free);
	size = 0;
	specifications = (char **)ft_lst_to_array(lst, &size);
	ft_lstclear(&lst, (void (*)(void *))ft_voidnop);
	return (specifications);
}

char	*generate_specification(char cs, int field_width, int precision, bool flag_sharp, bool flag_minus, bool flag_plus, bool flag_zero, bool flag_space)
{
	char	buf[100];
	char	*tmp;
	int		index;

	index = 0;
	buf[index++] = '%';
	if (flag_sharp)
		buf[index++] = '#';
	if (flag_minus)
		buf[index++] = '-';
	if (flag_plus)
		buf[index++] = '+';
	if (flag_zero)
		buf[index++] = '0';
	if (flag_space)
		buf[index++] = ' ';
	if (field_width > 0)
	{
		tmp = ft_itoa(field_width);
		index += ft_strlcpy(buf + index, tmp, 100 - index);
		free(tmp);
	}
	if (precision > 0)
	{
		tmp = ft_itoa(precision);
		buf[index++] = '.';
		index += ft_strlcpy(buf + index, tmp, 100 - index);
		free(tmp);
	}
	buf[index++] = cs;
	buf[index] = '\0';
	return (ft_strdup(buf));
}
