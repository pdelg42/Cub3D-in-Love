/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:41:56 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/30 13:46:25 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTFT_H
# define LISTFT_H

typedef struct s_node
{
	int				id;
	int				status;
	char			*box;
	char			*type;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*new_(char *content, int id);
void	add_h(t_node **h, t_node *node);
void	add_t(t_node **h, t_node *node);
void	del_h(t_node **h);
void	del_t(t_node **h);	
void	del_node(t_node **stack, int n);
void	freelist(t_node **h);
void	freenode(t_node	*h);
void	printlist(t_node **h);
void	deinit(t_node *node);
void	relister(t_node **h);
int		len_list(t_node	**h);
char	**list_to_matrix(t_node **head);
t_node	*matrix_to_list(char **matrix);
char	**list_to_matrix_dest(t_node **head, int dest);
char	**list_to_matrix_from(t_node **head, int from);
int		src_in_list(t_node	**h, char *field);
void	list_point_to(t_node **list, int id);
char	*key_fetcher(char *content);
void	type_eraser(t_node *h);
void	freecontent(t_node	*h);

#endif