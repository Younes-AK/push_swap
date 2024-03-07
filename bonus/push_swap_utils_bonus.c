/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:12:39 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 15:52:05 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*create_linkedlist(void)
{
	t_linkedlist	*newlist;

	newlist = (t_linkedlist *)malloc(sizeof(t_linkedlist));
	if (!newlist)
		return (NULL);
	newlist->head = NULL;
	return (newlist);
}

void	append(t_linkedlist *list, int mydata)
{
	t_node	*node;
	t_node	*iter;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return ;
	node->data = mydata;
	node->index = -1;
	node->next = NULL;
	if (list->head == NULL)
	{
		list->head = node;
		return ;
	}
	iter = list->head;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = node;
}

void	addto_front(t_linkedlist *list, t_node *node)
{
	if (list == NULL || node == NULL)
		return ;
	if (list->head == NULL)
	{
		node ->next = NULL;
		list->head = node;
		return ;
	}
	node->next = list->head;
	list->head = node;
}

int	is_sort(t_linkedlist *list)
{
	t_node	*curr;
	t_node	*prev;

	curr = list->head;
	while (curr->next)
	{
		prev = curr;
		if (prev->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

t_node	*last_node(t_linkedlist *list)
{
	t_node	*iter;

	iter = list->head;
	while (iter->next)
		iter = iter->next;
	return (iter);
}
