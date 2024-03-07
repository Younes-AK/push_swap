/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:31:03 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 14:37:26 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getmax(t_linkedlist *a)
{
	t_node	*max;
	t_node	*curr;

	curr = a->head;
	max = curr;
	while (curr)
	{
		if (max->data < curr->data)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

void	push_back2(t_linkedlist *a, t_linkedlist *b, int l)
{
	int	i;

	sort_three(a);
	i = 0;
	while (i < l)
	{
		push_ab(a, b, 'a');
		rotate(a, NULL, 'a');
		i++;
	}
}

void	sort_five(t_linkedlist *a, t_linkedlist *b, int len)
{
	int		i;
	int		l;
	t_node	*max;

	i = 0;
	if (len == 4)
		l = 1;
	else
		l = 2;
	while (i < l)
	{
		max = getmax(a);
		while (max != a->head)
		{
			if (max == a->head->next)
				swap_ab(a, NULL, 'a');
			else if (max == a->head->next->next)
				rotate(a, NULL, 'a');
			else
				rotate_rev(a, NULL, 'a');
		}
		push_ab(a, b, 'b');
		i++;
	}
	push_back2(a, b, l);
}
