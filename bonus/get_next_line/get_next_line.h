/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:37:49 by yakazdao          #+#    #+#             */
/*   Updated: 2024/02/29 13:02:09 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10
# endif

char	*get_next_line(int fd);
int		ft_found_newline(char *str);
char	*ftstrdup(char *str);
size_t	ftstrlen(char *str);
char	*ftstrjoin(char *s1, char *s2);
#endif
