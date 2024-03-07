/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:37:48 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 14:40:18 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_linkedlist *a)
{
	int		max;
	t_node	*curr;

	curr = a->head;
	max = curr->data;
	while (curr)
	{
		if (max < curr->data)
			max = curr->data;
		curr = curr->next;
	}
	return (max);
}

void	sort_three(t_linkedlist *a)
{
	int	max;
	int	i;

	i = 0;
	max = get_max(a);
	while (!is_sort(a))
	{
		i++;
		if (max == a->head->data)
			rotate(a, NULL, 'a');
		else if (max == a->head->next->data)
			rotate_rev(a, NULL, 'a');
		if (a->head->data > a->head->next->data)
			swap_ab(a, NULL, 'a');
	}
}
