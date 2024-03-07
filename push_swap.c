/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:31:37 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/07 16:22:12 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_linkedlist *a, t_linkedlist *b, t_push_swap *vars)
{
	if (!is_sort(a))
	{
		if (vars->num_word == 2)
			swap_ab(a, NULL, 'a');
		else if (vars->num_word == 3)
			sort_three(a);
		else if (vars->num_word == 5 || vars->num_word == 4)
			sort_five(a, b, vars->num_word);
		else
		{
			indexing(a, vars);
			if (vars->num_word <= 100)
				sorting(a, b, 15);
			else
				sorting(a, b, 37);
		}
	}
}

int	main(int argc, char **argv)
{
	t_push_swap		vars;
	t_linkedlist	*a;
	t_linkedlist	*b;

	a = create_linkedlist();
	b = create_linkedlist();
	if (!a || !b)
		ft_free(a, b, "cannot allocate memory using malloc\n");
	if (argc == 1)
		exit(1);
	else if ((argc == 2 && argv[1][0] == '\0') || ft_is_empty(argv[1]))
		err_msg1("Error\n");
	parsing(argc - 1, argv, &vars);
	if (vars.num_word >= 1)
	{
		init_stack(a, &vars);
		push_swap(a, b, &vars);
		free(vars.arr);
	}
	free_linkedlist(b);
	free_linkedlist(a);
}
