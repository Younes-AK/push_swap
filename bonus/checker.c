/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:04:56 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/07 15:59:55 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_is_valid(char *str)
{
	if (!ft_strncmp(str, "sa\n", 3) || !ft_strncmp(str, "ra\n", 3)
		||!ft_strncmp(str, "rra\n", 4) || !ft_strncmp(str, "pa\n", 3)
		|| !ft_strncmp(str, "sb\n", 3) || !ft_strncmp(str, "rb\n", 3)
		|| !ft_strncmp(str, "rrb\n", 4) || !ft_strncmp(str, "pb\n", 3)
		|| !ft_strncmp(str, "ss\n", 3) || !ft_strncmp(str, "rr\n", 3)
		|| !ft_strncmp(str, "rrr\n", 4))
		;
	else
		err_msg1("error");
}

void	apply_instructions(t_linkedlist *a, t_linkedlist *b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap_ab(a, NULL, 'a');
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(a, NULL, 'a');
	else if (!ft_strncmp(str, "rra\n", 4))
		rotate_rev(a, NULL, 'a');
	else if (!ft_strncmp(str, "pa\n", 3))
		push_ab(a, b, 'a');
	else if (!ft_strncmp(str, "sb\n", 3))
		swap_ab(NULL, b, 'b');
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(NULL, b, 'b');
	else if (!ft_strncmp(str, "rrb\n", 4))
		rotate_rev(NULL, b, 'b');
	else if (!ft_strncmp(str, "pb\n", 3))
		push_ab(a, b, 'b');
	else if (!ft_strncmp(str, "ss\n", 3))
		swap_ab(a, b, 'c');
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate(a, b, 'c');
	else if (!ft_strncmp(str, "rrr\n", 4))
		rotate_rev(a, b, 'c');
	else
		err_msg1("Error\n");
}

void	try_to_sort(t_linkedlist *a, t_linkedlist *b, t_push_swap *vars)
{
	char	**temp;
	int		n;
	int		i;

	i = 0;
	temp = ft_split(vars->full_str, ' ', &n);
	if (!temp)
		return ;
	while (i < n)
	{
		apply_instructions(a, b, temp[i]);
		i++;
	}
	free_strs(temp, n);
}

void	read_operations(t_linkedlist *a, t_linkedlist *b, t_push_swap *vars)
{
	vars->str = ft_strdup("");
	while (1)
	{
		vars->buffer = get_next_line(0);
		if (vars->buffer == NULL)
			break ;
		check_is_valid(vars->buffer);
		vars->full_str = ft_strjoin(vars->str, vars->buffer);
		if (!vars->full_str)
			err_msg1("strjoin cannot allocate memory");
		free(vars->buffer);
		free(vars->str);
		vars->str = vars->full_str;
	}
	try_to_sort(a, b, vars);
	free(vars->str);
	if (stack_size(b) > 0)
		write(1, "KO\n", 3);
	else if (is_sort(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		read_operations(a, b, &vars);
		free(vars.arr);
	}
	free_linkedlist(b);
	free_linkedlist(a);
}
