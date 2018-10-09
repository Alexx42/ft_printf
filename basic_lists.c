/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:07:38 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/04 22:07:39 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse(t_list **lst)
{
	t_list *current;
	t_list *prev;
	t_list *next;

	prev = NULL;
	next = NULL;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}

void	append(t_list **head_ref, char *new_data, int content_size)
{
	t_list *new;
	t_list *last;

	last = *head_ref;
	new = (t_list*)(malloc(sizeof(t_list)));
	new->content = ft_strdup(new_data);
	new->next = NULL;
	new->content_size = content_size;
	if (*head_ref == NULL)
	{
		*head_ref = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
 }

void	append_char(t_list **head_ref, char new_data, int content_size)
{
	t_list *new;
	t_list *last;

	last = *head_ref;
	new = (t_list*)(malloc(sizeof(t_list)));
	new->content = strdup(&new_data);
	new->next = NULL;
	new->content_size = content_size;
	if (*head_ref == NULL)
	{
		*head_ref = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

int		list_size(t_list *lst)
{
	int count;
	t_list *cur;

	cur = lst;
	count = 0;
	while (cur != NULL)
	{
		count+=ft_strlen(cur->content);
		cur = cur->next;
	}
	return (count);
}

void	print_list(t_list *lst)
{

	while (lst != NULL)
	{
		printf("%s", lst->content);
		lst = lst->next;
	}
}


void	delete_list(t_list **head_ref)
{
	t_list	*current;
	t_list	*next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		free(current->content);
		current = next;
	}
	*head_ref = NULL;
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */
void push(t_list** head_ref, char *new_data)
{
	/* 1. allocate node */
	t_list *new_node = malloc(sizeof(t_list));

	/* 2. put in the data  */
	new_node->content  = strdup(new_data);

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}