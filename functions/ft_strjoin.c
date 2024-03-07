/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:55:32 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/03 15:50:20 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_push_swap	vars;
	char		*allstr;

	vars.i = 0;
	vars.j = 0;
	if (!s1 || !s2)
		return (NULL);
	allstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!allstr)
		return (NULL);
	while (s1[vars.i])
	{
		allstr[vars.i] = s1[vars.i];
		vars.i++;
	}
	allstr[vars.i] = ' ';
	vars.i++;
	while (s2[vars.j])
	{
		allstr[vars.i] = s2[vars.j];
		vars.j++;
		vars.i++;
	}
	allstr[vars.i] = '\0';
	return (allstr);
}
