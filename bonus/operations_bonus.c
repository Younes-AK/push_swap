/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:26 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 15:12:17 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_ab(t_linkedlist *a, t_linkedlist *b, char swap)
{
	t_node	*curr;
	t_node	*prev;

	if (swap == 'a' && stack_size(a) > 1)
	{
		prev = a->head;
		curr = prev->next;
		prev->next = curr->next;
		curr->next = prev;
		a->head = curr;
	}
	else if (swap == 'b' && stack_size(b) > 1)
	{
		prev = b->head;
		curr = prev->next;
		prev->next = curr->next;
		curr->next = prev;
		b->head = curr;
	}
	else if (swap != 'a' && swap != 'b')
	{
		swap_ab(a, b, 'a');
		swap_ab(a, b, 'b');
	}
}

void	push_ab(t_linkedlist *a, t_linkedlist *b, char ab)
{
	t_node	*temp;

	if (ab == 'b' && stack_size(a) > 0)
	{
		temp = a->head;
		a->head = a->head->next;
		addto_front(b, temp);
	}
	else if (ab == 'a' && stack_size(b) > 0)
	{
		temp = b->head;
		b->head = b->head->next;
		addto_front(a, temp);
	}
}

void	rotate(t_linkedlist *a, t_linkedlist *b, char ab)
{
	t_push_swap	vars;

	if (ab == 'a' && stack_size(a) > 1)
	{
		vars.temp = a->head;
		a->head = a->head->next;
		vars.last = last_node(a);
		vars.last->next = vars.temp;
		vars.temp->next = NULL;
	}
	else if (ab == 'b' && stack_size(b) > 1)
	{
		vars.temp = b->head;
		b->head = b->head->next;
		vars.last = last_node(b);
		vars.last->next = vars.temp;
		vars.temp->next = NULL;
	}
	else if (ab != 'a' && ab != 'b')
	{
		rotate(a, b, 'a');
		rotate(a, b, 'b');
	}
}

void	rotate_rev(t_linkedlist *a, t_linkedlist *b, char ab)
{
	t_push_swap	vars;

	if (ab == 'a' && stack_size(a) > 1)
	{
		vars.prev = before_last(a);
		vars.last = last_node(a);
		vars.prev->next = NULL;
		vars.last->next = a->head;
		a->head = vars.last;
	}
	else if (ab == 'b' && stack_size(b) > 1)
	{
		vars.prev = before_last(b);
		vars.last = last_node(b);
		vars.prev->next = NULL;
		vars.last->next = b->head;
		b->head = vars.last;
	}
	else if (ab != 'a' && ab != 'b')
	{
		rotate_rev(a, b, 'a');
		rotate_rev(a, b, 'b');
	}
}
