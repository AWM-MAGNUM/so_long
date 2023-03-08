/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:44:50 by bel-kase          #+#    #+#             */
/*   Updated: 2023/03/06 23:44:42 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);
char	*ft_the_reader(int fd, char *unreal);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, char *src, int len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_extracteur_the_line(char *BIG_LINE);
char	*ft_update_42(char *META);
#endif
