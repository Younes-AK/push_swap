/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:57:48 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 15:02:44 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_linkedlist *a, t_linkedlist *b, char swap)
{
	t_node	*curr;
	t_node	*prev;

	prev = a->head;
	curr = prev->next;
	if (swap == 'a')
	{
		prev->next = curr->next;
		curr->next = prev;
		a->head = curr;
		write(1, "sa\n", 3);
	}
	else if (swap == 'b')
	{
		prev->next = curr->next;
		curr->next = prev;
		b->head = curr;
		write(1, "sb\n", 3);
	}
	else
	{
		swap_ab(a, b, 'a');
		swap_ab(a, b, 'b');
	}
}

void	push_ab(t_linkedlist *a, t_linkedlist *b, char ab)
{
	t_node	*temp;

	if (ab == 'b')
	{
		temp = a->head;
		a->head = a->head->next;
		addto_front(b, temp);
		write(1, "pb\n", 3);
	}
	else if (ab == 'a')
	{
		temp = b->head;
		b->head = b->head->next;
		addto_front(a, temp);
		write(1, "pa\n", 3);
	}
}

void	rotate(t_linkedlist *a, t_linkedlist *b, char ab)
{
	t_push_swap	vars;

	if (ab == 'a')
	{
		vars.temp = a->head;
		a->head = a->head->next;
		vars.last = last_node(a);
		vars.last->next = vars.temp;
		write(1, "ra\n", 3);
	}
	else if (ab == 'b')
	{
		vars.temp = b->head;
		b->head = b->head->next;
		vars.last = last_node(b);
		vars.last->next = vars.temp;
		write(1, "rb\n", 3);
	}
	else
	{
		rotate(a, b, 'a');
		rotate(a, b, 'b');
	}
	vars.temp->next = NULL;
}

void	rotate_rev(t_linkedlist *a, t_linkedlist *b, char ab)
{
	t_push_swap	vars;

	if (ab == 'a')
	{
		vars.prev = before_last(a);
		vars.last = last_node(a);
		vars.prev->next = NULL;
		vars.last->next = a->head;
		a->head = vars.last;
		write(1, "rra\n", 4);
	}
	else if (ab == 'b')
	{
		vars.prev = before_last(b);
		vars.last = last_node(b);
		vars.prev->next = NULL;
		vars.last->next = b->head;
		b->head = vars.last;
		write(1, "rrb\n", 4);
	}
	else
	{
		rotate_rev(a, b, 'a');
		rotate_rev(a, b, 'b');
	}
}
