/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:50:53 by sgouzi            #+#    #+#             */
/*   Updated: 2023/12/02 09:50:54 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# if BUFFER_SIZE > 2147483647
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		we_have_a_problem(int fd, char **str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*get_rest(char *left_str);

#endif
