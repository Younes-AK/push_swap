/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:54:10 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 14:57:09 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min(t_linkedlist *list)
{
	t_node	*curr;
	t_node	*min;
	int		min_val;

	min = NULL;
	if (!list)
		return (NULL);
	min_val = INT_MAX;
	curr = list->head;
	while (curr)
	{
		if (min_val > curr->data && curr->index == -1)
		{
			min_val = curr->data;
			min = curr;
		}
		curr = curr->next;
	}
	return (min);
}

void	indexing(t_linkedlist *list, t_push_swap *vars)
{
	t_node	*min;
	int		i;

	i = 0;
	while (i < vars->num_word)
	{
		min = get_min(list);
		if (min->index == -1)
			min->index += i + 1;
		i++;
	}
}
