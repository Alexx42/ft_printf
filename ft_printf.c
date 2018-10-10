/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:13:49 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/07 01:09:30 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list args;
	va_list args2;
	t_flags *flags;
	t_list *lst;
	char buf[4096];
	char *arr;
	int len;
	int i;

	i = 0;
	len = 0;
	va_start(args, fmt);
	lst = NULL;
	while (*fmt)
	{
		arr = NULL;
		if (*fmt == '%')
		{
			flags = init_list();
			va_copy(args2, args);
			buf[i] = '\0';
			fmt++;
			parse_everything(&flags, &fmt);
			append(&lst, buf, i);
			i = 0;
			arr = choose_conversion(flags, fmt, args);
			flags->len = arr ? (int)ft_strlen(arr) : 1;
			flags->len_total = handle_flags(&lst, flags, args2);
			flags->flags_2 = handle_flags2(&lst, flags, &arr, fmt);
			if (arr)
				value_zero(&arr, &flags, fmt);
			if (arr == NULL)
			{
				len += 1;
				arr = malloc(1);
				*arr = 0;
			}
			append(&lst, arr, flags->len);
			free(arr);
			free(flags);
		}
		else
		{
			buf[i] = *fmt;
			i++;
		}
		fmt++;
		print_list(lst);
		len += list_size(lst);
		delete_list(&lst);
	}
	buf[i] = '\0';
	append(&lst, buf, i);
	len += list_size(lst);
	print_list(lst);
	delete_list(&lst);
	return (len);
}
