/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:18:50 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 15:22:25 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_ischar(int c)
{
	if ((c >= 32 && c <= 42) || (c >= 46 && c <= 47)
		|| (c >= 58 && c <= 126) || c == 44)
		return (1);
	return (0);
}

int	ft_is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
	{
		if (s[i] >= 9 && s[i] <= 13)
			return (1);
		i++;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}

t_node	*before_last(t_linkedlist *list)
{
	t_node	*iter;

	iter = list->head;
	while (iter->next->next)
		iter = iter->next;
	return (iter);
}

void	init_stack(t_linkedlist *list, t_push_swap *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_word)
	{
		append(list, vars->arr[i]);
		i++;
	}
}

int	stack_size(t_linkedlist *list)
{
	int		i;
	t_node	*iter;

	i = 0;
	iter = list->head;
	while (iter)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}
