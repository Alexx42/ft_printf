/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 22:39:33 by ale-goff          #+#    #+#             */
/*   Updated: 2019/05/26 21:53:42 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	valid_free(int *len, t_flags *flags, char **arr, t_list_pf **lst)
{
	check_null(len, arr);
	free_content(flags, lst, (*arr));
}

void	init_beg(t_list_pf **lst, int *i)
{
	(*i) = 0;
	(*lst) = NULL;
}

void	non_conversion(const char *fmt, char *buf, int *i)
{
	buf[(*i)] = *fmt;
	(*i)++;
}
