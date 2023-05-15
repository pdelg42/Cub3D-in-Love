/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:14:07 by sgerace           #+#    #+#             */
/*   Updated: 2023/05/12 22:38:27 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include "cub.h"

//gc structs
typedef struct s_xfillmv
{
	int		i;
	int		j;
	int		len;
	int		quotes;
	int		qcount;
	int		num_w;
	char	c;
}	t_xfillmv;

typedef struct s_xsubstr
{
	int	i;
	int	len;
}	t_xsubstr;

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}	t_garbage;

//garbage collector functions

void		*gc_alloc(t_garbage **head, int size, int count);
void		ft_garbage_collector(t_garbage **head);
void		add_node(t_garbage **head, void *ptr);

//modified libft

char		*ft_substr_m(t_garbage **garbage, char const *s, t_xsubstr sub);
char		*ft_strdup_m(t_garbage **garbage, const char *s1);
char		*ftm_itoa(t_garbage **garbage, int n);
char		**ftm_split(t_garbage **garbage, char const *s, char c);
char		*ftm_strjoin(t_garbage **g, char const *s1, char const *s2, int f);
void		ft_init_fmv(t_xfillmv *fmv);
char		*ft_strtrim_gc(t_garbage** gc, const char *s1, const char *set);
#endif
