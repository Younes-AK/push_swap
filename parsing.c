/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:37:34 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/07 11:31:11 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int n, int *arr, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (n == arr[i])
			count++;
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_is_dup_flow(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648
			|| is_duplicate(arr[i], arr, size))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str || ((ft_strlen(str) == 1) && (str[i] == '-' || str[i] == '+')))
		return (0);
	while (str[i] >= 9 && (str[i] <= 13 || str[i] == ' '))
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			count++;
		else if ((str[i + 1] == '-' || str[i + 1] == '+')
			&& (str[i] >= '0' && str[i] <= '9'))
			return (0);
		if (ft_ischar(str[i]) || count > 1)
			return (0);
		i++;
	}
	return (1);
}

void	get_allarg(int len, char **av, t_push_swap *vars)
{
	vars->j = 0;
	vars->temp_split = ft_strdup(av[1]);
	if (len > 1)
	{
		while (vars->j < len)
		{
			if (ft_is_empty(av[vars->j + 1]))
				err_msg1("Error\n");
			vars->j++;
		}
		vars->j = 0;
		while (vars->j < len - 1)
		{
			vars->str_arg = ft_strjoin(vars->temp_split, av[vars->j + 2]);
			free (vars->temp_split);
			if (!vars->str_arg)
				err_msg1("cannot allocate memory using malloc");
			vars->temp_split = vars->str_arg;
			vars->j++;
		}
	}
	vars->strs = ft_split(vars->temp_split, ' ', &vars->num_word);
	if (!vars->strs)
		err_msg1("cannot allocate memory using malloc");
}

void	parsing(int ac, char **av, t_push_swap *vars)
{
	vars->i = 0;
	get_allarg(ac, av, vars);
	vars->arr = malloc(sizeof(int) * (vars->num_word));
	if (!vars->arr)
		err_msg1("cannot allocate memory using malloc");
	while (vars->i < vars->num_word)
	{
		if (is_valid(vars->strs[vars->i]))
			vars->arr[vars->i] = ft_atoi(vars->strs[vars->i]);
		else
			err_msg2("Error\n", vars->arr);
		vars->i++;
	}
	if (check_is_dup_flow(vars->arr, vars->num_word))
		err_msg2("Error\n", vars->arr);
	if (ac > 1)
	{
		free(vars->str_arg);
		free_strs(vars->strs, vars->num_word);
	}
	else
	{
		free_strs(vars->strs, vars->num_word);
		free(vars->temp_split);
	}
}
