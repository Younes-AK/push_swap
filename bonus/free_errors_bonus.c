/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:03:35 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/07 16:02:57 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_linkedlist(t_linkedlist *list)
{
	t_node	*curr;
	t_node	*next;

	if (!list)
		return ;
	curr = list->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(list);
}

void	free_strs(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	err_msg1(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	err_msg2(char *message, int *arr)
{
	free(arr);
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	ft_free(t_linkedlist *a, t_linkedlist*b, char *message)
{
	free(a);
	free(b);
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
