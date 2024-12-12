/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:50 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/12 19:17:43 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>

int		ftt_strlen(char *str);
char	*ft_isnewline(char *s);
char	*ftt_strdup(char *line);
char	*ftt_strjoin(char *s1, char *s2);
void	ftt_memmove(char *buffer, char *storage);
char	*ftt_bzero(char *str, int i);
char	*ft_read_buf_is_empty(char *buffer, int fd);
char	*ft_read_buf_is_full(char *buffer, int fd);
char	*ft_setline(char *line);
char	*get_next_line(int fd);

#endif
