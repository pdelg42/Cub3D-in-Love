/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:31:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/10 20:36:56 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "cub.h"

long long	a_(char *str, int len_base);
int			ft_isdigit(char c);
int			ft_isnum(char *str);
int			ft_clamp(const int val, const int min, const int max);
int			ft_strcmp(char *s1, char *s2);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
void		freematrix(char **splitted, int i);
char		*ft_strdup(const char *s1);
int			row_counter(char **matrix);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isspace(int c);
int			ft_isprint(int c);
void		white();
void		red();
void		purple();
char		*ft_strtrim(const char *s1, const char *set);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *b, size_t n);
char        *ft_strstr(char *str, char *to_find);

#endif
