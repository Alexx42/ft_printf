/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:07:38 by ale-goff          #+#    #+#             */
/*   Updated: 2019/05/26 22:03:04 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append(t_list_pf **head_ref, char *new_data, int content_size)
{
	t_list_pf *new;
	t_list_pf *last;

	last = *head_ref;
	new = (t_list_pf*)(malloc(sizeof(t_list_pf)));
	new->content = ft_strdup_pf(new_data);
	new->next = NULL;
	new->content_size = (size_t)content_size;
	if (*head_ref == NULL)
	{
		*head_ref = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

int		list_size(t_list_pf *lst)
{
	int			count;
	t_list_pf	*cur;

	cur = lst;
	count = 0;
	while (cur != NULL)
	{
		count += ft_strlen_pf(cur->content);
		cur = cur->next;
	}
	return (count);
}

void	print_list_pf(t_list_pf *lst)
{
	while (lst != NULL)
	{
		write(1, lst->content, (size_t)lst->content_size);
		lst = lst->next;
	}
}

void	delete_list(t_list_pf **head_ref)
{
	t_list_pf	*current;
	t_list_pf	*next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

void	push_lst(t_list_pf **head_ref, char *new_data, int content_size)
{
	t_list_pf *new_node;

	new_node = malloc(sizeof(t_list_pf));
	new_node->content = ft_strdup_pf(new_data);
	new_node->content_size = (size_t)content_size;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
