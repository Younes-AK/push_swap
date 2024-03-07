/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:46:48 by yakazdao          #+#    #+#             */
/*   Updated: 2024/03/07 15:57:26 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}				t_node;

typedef struct s_linkedlist
{
	t_node	*head;
}			t_linkedlist;

typedef struct s_push_swap
{
	char	**strs;
	char	*allarg;
	char	*str_arg;
	int		*arr;
	int		num_word;
	char	*temp_split;

	t_node	*temp;
	t_node	*prev;
	t_node	*last;
	char	*full_str;
	char	*buffer;
	char	*str;
	int		i;
	int		j;
}			t_push_swap;

/* start ==> operations functions*/
void	push_ab(t_linkedlist *a, t_linkedlist *b, char ab);
void	swap_ab(t_linkedlist *a, t_linkedlist *b, char swap);
void	rotate(t_linkedlist *a, t_linkedlist *b, char ab);
void	rotate_rev(t_linkedlist *a, t_linkedlist *b, char ab);
/* end ==> operations functions*/

/* start ==> linked-list functions*/
void	*create_linkedlist(void);
void	append(t_linkedlist *list, int mydata);
void	addto_front(t_linkedlist *list, t_node *node);
void	free_linkedlist(t_linkedlist *list);
int		is_sort(t_linkedlist *list);
t_node	*last_node(t_linkedlist *list);
t_node	*before_last(t_linkedlist *list);
void	init_stack(t_linkedlist *list, t_push_swap *vars);
/* end ==> linked-list functions*/

/* start ==> libft functions*/
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c, int *n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_ischar(int c);
int		ft_is_empty(char *s);
/* end ==> libft functions*/

/* start ==> push-swap functions*/
void	parsing(int ac, char **av, t_push_swap *vars);
void	err_msg1(char *message);
void	err_msg2(char *message, int *arr);
void	free_strs(char **strs, int size);
void	ft_free(t_linkedlist *a, t_linkedlist*b, char *message);
void	sort_three(t_linkedlist *a);
void	sort_five(t_linkedlist *a, t_linkedlist *b, int len);
void	indexing(t_linkedlist *list, t_push_swap *vars);
int		stack_size(t_linkedlist *list);
void	sorting(t_linkedlist *a, t_linkedlist *b, int len);
/* end ==> push-swap functions*/

/* start ==> push-swap-bonus functions*/
void	push_swap_bonus(t_linkedlist *a, t_linkedlist *b, t_push_swap *vars);
char	*get_next_line(int fd);

#endif