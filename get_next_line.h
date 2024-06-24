/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:52 by leonel            #+#    #+#             */
/*   Updated: 2024/06/24 17:29:51 by leonel           ###   ########.fr       */
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

# define BUFFER_SIZE 8

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
char	*ft_strdup(const char *s, int len);

#endif