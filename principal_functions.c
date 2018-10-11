/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 00:11:14 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/10 00:11:15 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_everything(t_flags **flags, const char **fmt)
{
	parse_args(flags, fmt);
	parse_args_precision(flags, fmt);
	parse_args_modifier(flags, fmt);
}

void	assign_value(const char *fmt, t_flags **flags, t_list **lst, char **arr)
{
	(*flags)->len = (*arr) ? (int)ft_strlen((*arr)) : 1;
	(*flags)->len_total = handle_flags(lst, (*flags), (*arr));
	(*flags)->flags_2 = handle_flags2(lst, (*flags), arr, fmt);
	if ((*arr))
		value_zero(arr, flags, fmt);
}

void	free_content(t_flags *flags, t_list **lst, char *arr)
{
	append(lst, arr, flags->len);
//	free(arr);
	free(flags);
}

void	get_values(char *buf, int i, const char **fmt, t_flags **flags)
{
	(*flags) = init_list();
	buf[i] = '\0';
	(*fmt)++;
	parse_everything(flags, fmt);
}

void	init_values(int *i, char **arr)
{
	*arr = NULL;
	*i = 0;
}
