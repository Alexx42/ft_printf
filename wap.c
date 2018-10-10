/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:17:40 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/07 01:08:09 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_zero(char **arr, t_flags **flags)
{
	if ((*arr)[0] == '0' && (*flags)->len == 1)
	{
		(*flags)->zeros += 1;
	}
}

int		width(t_list **lst, t_flags *flags, char **arr, const char *fmt)
{
	int i;
	int len;
	int count;
	int j = flags->len;


	count =  (flags->precision > flags->len && flags->len > 0) ? (flags->precision): flags->len;
	if (flags->hash)
		len = hash_flags(lst, fmt, arr);
	else
		len = flags->len_total;
	i = 0;
	if (*arr)
		parse_zero(arr, &flags);
	if (*arr)
		value_negative(arr, lst, &flags);
	if (flags->width > flags->precision)
	{
		if (flags->minus == 0)
		{
			while (i < ((flags->width + flags->zeros) - count) - (len))
			{
				if (flags->o_flag && len == 0)
				{
					if (flags->width - flags->precision != flags->len)
						append(lst, "0", 1);
					else
						append(lst, " ", 1);

				}
				else if (flags->o_flag && len > 0)
					append(lst, "0", 1);
				else if (len > 0 && flags->o_flag == 0)
					push(lst, " ", 1);
				else
					append(lst, " ", 1);
				i++;
			}
		}
		else if (flags->minus)
		{

			if (flags->precision - flags->len == 1)
				append(lst, "0", 1);
			while (i < (flags->width - count) - len && flags->len > 0)
			{
				(*arr)[j + i] = ' ';
				flags->len++;
				i++;
			}
			(*arr)[flags->len + i] = '\0';
		}
	}
	if (flags->precision > 0)
		return (precision_handle(lst, flags, arr));
	return (len);
}


void	value_negative(char **arr, t_list **lst, t_flags **flags)
{
	int i;

	i = 0;
	if (*arr && arr)
	{
		if (*arr[0] == '-' && ((*flags)->len_total > 0 || (*flags)->o_flag > 0 ||
			(*flags)->precision > (*flags)->len))
		{
			while (i < (*flags)->len - 1)
			{
				(*arr)[i] = (*arr)[i + 1];
				i++;
			}
			(*arr)[i] = '\0';
			(*flags)->len -= 1;
			append(lst, "-", 1);
		}
	}
}

void	value_zero(char **arr, t_flags **flags, const char *fmt)
{
	if (*arr[0] == '0' && (*flags)->len == 1 && ((*flags)->dot == 1 ||
		(*flags)->precision == 0) && ((*flags)->flags_2 == 2 || ((*fmt == 'x' &&
		(*flags)->precision == 0)) || ((*fmt == 'o' && (*flags)->precision == 0
		&& (*flags)->hash == 0)) || (((*flags)->dot == 1 && *fmt == 'd'))))
	{
		*arr[0] = '\0';
		(*flags)->len--;
	}
}

int 	precision_handle(t_list **lst, t_flags *flags, char **arr)
{
	int i;
	int j;

	i = 0;
	if (!(*arr) || !arr)
		return (0);
	if (atoi(*arr) != 0)
	{
		while (i < flags->precision - flags->len)
		{
			append(lst, "0", 1);
			i++;
		}
	}

	else if (atoi(*arr) == 0)
	{
		j = flags->len;
		while (i < flags->precision && flags->width > flags->precision && flags->len > 0)
		{
			if (flags->minus == 0)
				append(lst, " ", 1);
			else if (flags->minus == 1)
			{
				if (flags->width > flags->precision && flags->width > flags->len)
					append(lst, " ", 1);
				else
				{
					(*arr)[i + j] = ' ';
					flags->len++;
				}
			}
			i++;
		}
		i = 0;
		j = flags->len;
		while (i < j - flags->precision)
		{
			(*arr)[i + j - flags->precision] = 0;
			flags->len--;
			i++;
		}
	}
	return (i);
}


