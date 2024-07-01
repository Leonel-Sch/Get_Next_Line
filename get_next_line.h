/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:52 by leonel            #+#    #+#             */
/*   Updated: 2024/07/01 19:15:57 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
char	*ft_strdup(const char *s, int len);

#endif