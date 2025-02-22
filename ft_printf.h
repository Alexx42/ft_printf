/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:16:09 by ale-goff          #+#    #+#             */
/*   Updated: 2019/05/26 22:03:04 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <string.h>
# include <wchar.h>
# include <limits.h>

typedef	struct		s_list_pf
{
	void				*content;
	size_t				content_size;
	struct s_list_pf	*next;
}					t_list_pf;

typedef struct		s_flags
{
	int				hash;
	int				o_flag;
	int				minus;
	int				plus;
	int				space;
	int				numbers;
	int				double_h;
	int				one_h;
	int				one_l;
	int				double_l;
	int				one_j;
	int				one_z;
	int				width;
	int				precision;
	int				dot;
	int				len;
	int				len_total;
	int				zeros;
	int				flags_2;
	int				neg;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_putstr_pf(const char *str);
int					ft_putchar_pf(char c);
char				*conversion(const char *str, va_list args);
t_flags				*init_list_pf();
int					find_flags(t_flags *flags, const char **str);
char				*choose_conversion(t_flags *flags, const char *str,
					va_list args);
void				parse_args(t_flags **flags, const char **fmt);
int					validate_percentage(char c);
int					validate_flags(char c);
int					validate_modifier(char c);
void				parse_args_modifier(t_flags **flags, const char **fmt);
int					validate_precision(char c);
void				parse_args_precision(t_flags **flags, const char **fmt);
int					is_number(char c);
char				*ft_itoa_b_pf(unsigned long long value, unsigned char base,
					char upper);
char				*ft_itoa_b_pf_signed(long long value, unsigned char base,
					char upper);
void				append(t_list_pf **head_ref, char *new_data, int content_size);
int					hash_flags(t_list_pf **lst, const char *fmt, char **arr);
void				print_list_pf(t_list_pf *lst);
void				push_lst(t_list_pf **head_ref, char *new_data, int content_size);
void				parse_everything(t_flags **flags, const char **fmt);
int					plus_flags(t_list_pf **lst);
int					handle_flags(t_list_pf **lst, t_flags *flags, char *arr);
void				delete_list(t_list_pf **head_ref);
void				append_char(t_list_pf **head_ref, char new_data,
					int content_size);
int					list_size(t_list_pf *lst);
int					width(t_list_pf **lst, t_flags *flags, char **arr,
					const char *fmt);
int					handle_flags2(t_list_pf **lst, t_flags *flags, char **arr,
					const char *fmt);
int					precision_handle(t_list_pf **lst, t_flags *flags,
					char **arr);
char				*ft_strdup_pf(const char *s1);
char				*ft_strjoin_pf(char const *s1, char const *s2);
char				*ft_strcat_pf(char *dest, const char *src);
size_t				ft_strlen_pf(const char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
void				reverse(t_list_pf **lst);
int					is_carac(char c);
void				value_negative(char **arr, t_list_pf **lst, t_flags **flags);
void				value_zero(char **arr, t_flags **flags, const char *fmt);
void				parse_modifier_helper(t_flags **flags, const char **fmt);
void				ft_strdel(char **as);
char				*conversion_z(const char *str, va_list args);
char				*conversion_l(const char *str, va_list args);
char				*conversion_ll(const char *str, va_list args);
char				*conversion_j(const char *str, va_list args);
char				*ft_chartostr(char c);
void				width_zminus(t_list_pf **lst, t_flags *flags, int len);
void				protect_value(t_list_pf **lst, t_flags **flags, char **arr);
int					get_len(t_list_pf **lst, t_flags *flags, char **arr,
					const char *fmt);
int					precision_width(t_flags *flags);
void				parse_zero(char **arr, t_flags **flags);
void				arr_width(t_flags **flags, char **arr, int i[2]);
int					ft_atoi(const char *str);
void				precision_nb(t_list_pf **lst, t_flags *flags, int i);
void				precision_str(t_list_pf **lst, t_flags *flags, char **arr,
					int i[2]);
void				assign_value(const char *fmt, t_flags **flags, t_list_pf **lst,
					char **arr);
void				free_content(t_flags *flags, t_list_pf **lst, char *arr);
t_list_pf				*elem_list(const char *fmt, char *buf, int *len,
					va_list args);
void				check_null(int *len, char **arr);
void				renew(int *len, const char **fmt, t_list_pf **lst);
void				init_values(int *i, char **arr);
void				get_values(char *buf, int i, const char **fmt,
					t_flags **flags);
void				valid_free(int *len, t_flags *flags, char **arr,
					t_list_pf **lst);
void				init_beg(t_list_pf **lst, int *i);
void				non_conversion(const char *fmt, char *buf, int *i);
void				delete_list2(t_list_pf **head_ref, const char **fmt);
char				*ft_strdup_pf_wchar(wchar_t *s1);

#endif
