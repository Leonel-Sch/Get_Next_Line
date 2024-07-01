/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:49 by leonel            #+#    #+#             */
/*   Updated: 2024/07/01 19:37:26 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s, int len)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (strlen(s) + len) + 1);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strndup(const char *s, int nb)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * strlen(s) + 1);
	while (s[i] && i < nb)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i] && s1 != NULL)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	free((char *)s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	char		*temp;
	int			pos;
	int			i;
	int			reed;

	line = NULL;
	pos = 0;
	i = 0;
	reed = BUFFER_SIZE;
	temp = strdup(buffer);
	if (fd < 0)
	{
		free(temp);
		return (NULL);
	}
	if (strchr(buffer, '\n') == NULL)
	{
		while (strchr(buffer, '\n') == NULL && reed == BUFFER_SIZE)
		{
			reed = read(fd, buffer, BUFFER_SIZE);
			if (reed == 0)
			{
				free(temp);
				return (NULL);
			}
			if (reed == BUFFER_SIZE)
				temp = ft_strjoin(temp, buffer);
		}
	}
	else
		temp = strdup(buffer);
	if ((pos = ft_strchr_int(temp, '\n')) >= 0)
		line = strndup(temp, pos + 1);
	else
		line = strdup(temp);
	pos++;
	if (ft_strchr_int(buffer, '\n') >= 0)
	{
		if (strlen(temp) > BUFFER_SIZE)
		{
			while (temp[pos])
			{
				temp[i] = temp[pos];
				pos++;
				i++;
			}
			temp[i] = '\0';
			strcpy(buffer, temp);
		}
		else
		{
			while (buffer[pos])
			{
				buffer[i] = buffer[pos];
				pos++;
				i++;
			}
			buffer[i] = '\0';
		}
	}
	free(temp);
	return (line);
}

int	main(void)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open("./lol.txt", O_RDONLY);
	while (i <= 4)
	{
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	i++;
	}
	return (0);
}