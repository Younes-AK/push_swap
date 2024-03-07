/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:40:45 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 14:47:11 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_position(t_linkedlist *list, int max)
{
	int		i;
	t_node	*iter;

	i = 1;
	iter = list->head;
	while (iter)
	{
		if (iter->index == max)
			break ;
		i++;
		iter = iter->next;
	}
	return (i);
}

int	get_max_index(t_linkedlist *list)
{
	int		max;
	t_node	*curr;
	t_node	*prev;

	if (!list || !list->head)
		return (0);
	prev = list->head;
	curr = prev->next;
	max = prev->index;
	while (curr)
	{
		if (prev->index < curr->index)
			max = curr->index;
		prev = curr;
		curr = curr->next;
	}
	return (max);
}

void	push_back(t_linkedlist *a, t_linkedlist *b)
{
	int	max_index;
	int	pos;
	int	stack_mid;

	stack_mid = stack_size(b) / 2;
	max_index = stack_size(b) - 1;
	pos = get_max_position(b, max_index);
	while (stack_size(b) != 0)
	{
		stack_mid = (max_index + 1) / 2;
		if (pos < stack_mid)
			while (max_index != b->head->index)
				rotate(NULL, b, 'b');
		else
			while (max_index != b->head->index)
				rotate_rev(NULL, b, 'b');
		push_ab(a, b, 'a');
		max_index--;
		pos = get_max_position(b, max_index);
	}
}

void	sorting(t_linkedlist *a, t_linkedlist *b, int len)
{
	int	i;
	int	j;

	i = 0;
	j = len;
	while (stack_size(a))
	{
		if (a->head->index <= i)
		{
			push_ab(a, b, 'b');
			i++;
		}
		else if (a->head->index < (i + j))
		{
			push_ab(a, b, 'b');
			if (stack_size(b) > 1)
				rotate(NULL, b, 'b');
			i++;
		}
		else
			rotate(a, NULL, 'a');
	}
	push_back(a, b);
}
