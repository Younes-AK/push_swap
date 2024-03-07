/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:58:10 by yakazdao          #+#    #+#             */
/*   Updated: 2024/02/29 13:02:39 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ftstrlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ftstrdup(char *str)
{
	char	*ptr;
	int		i;	

	i = 0;
	if (!str)
		return (NULL);
	ptr = (char *)malloc(ftstrlen(str) + 1);
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		*(ptr + i) = str[i];
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ftstrjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*allstr;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ftstrdup(s2));
	if (!s2)
		return (ftstrdup(s1));
	allstr = (char *)malloc((ftstrlen(s1) + ftstrlen(s2) + 1));
	if (!allstr)
		return (NULL);
	while (s1[i])
	{
		allstr[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
		allstr[i++] = s2[j++];
	allstr[i] = '\0';
	return (allstr);
}
