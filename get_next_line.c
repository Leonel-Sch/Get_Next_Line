/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:49 by leonel            #+#    #+#             */
/*   Updated: 2024/06/25 14:03:49 by leonel           ###   ########.fr       */
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
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + len) + 1);
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
	dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
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
	int			i;
	int			j;
	char		*join;

	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i])
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
	return (join);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char *line;
	char *temp;
	int	pos;
	int i;

	line = NULL;
	temp = NULL;
	pos = 0;
	i = 0;
	while (strchr(buffer, '\n') == NULL)
	{
			temp = ft_strdup(buffer, ft_strlen(buffer));
			read(fd, buffer, BUFFER_SIZE);
			temp = ft_strjoin(temp, buffer);
	}
	if ((pos = ft_strchr_int(temp, '\n')) >= 0)
	{
		line = strndup(temp, pos + 1);
	}
	pos++;
	if (ft_strchr_int(buffer, '\n') > 0)
	{
		if (ft_strlen(temp) > BUFFER_SIZE)
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
	return (line);
}

int main(void)
{
	int fd;
	
	fd = open("./lol.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));

	return 0;
}