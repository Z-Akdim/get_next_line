/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:21:43 by zakdim            #+#    #+#             */
/*   Updated: 2019/12/22 12:43:52 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t count, size_t size);
int			get_next_line(int fd, char **line);
char		*str_get(char *rest, int i, char **line);
void		ft_bzero(void *s, size_t n);
char		*ft_chr(const char *s, int c);

#endif
