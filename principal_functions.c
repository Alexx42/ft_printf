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

void		parse_everything(t_flags **flags, const char **fmt)
{
	parse_args(flags, fmt);
	parse_args_precision(flags, fmt);
	parse_args_modifier(flags, fmt);
}
