/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:31:17 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/31 11:17:50 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>

# include "listft.h"

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
void		white(void);
void		red(void);
void		purple(void);
char		*ft_strtrim(const char *s1, const char *set);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *b, size_t n);
char		*ft_strstr(char *str, char *to_find);
void		*ft_memset(void *b, int c, size_t len);
void		ft_cpychar(char c, char **out);

#endif
