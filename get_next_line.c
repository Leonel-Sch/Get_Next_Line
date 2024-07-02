/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:49 by leonel            #+#    #+#             */
/*   Updated: 2024/07/02 20:08:00 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_error(char *buffer, char *temp)
{
	buffer[0] = '\0';
	free(temp);
}

void	ft_position(char **line, int pos, char *temp)
{
	if (pos >= 0)
		*line = ft_strndup(temp, pos + 1);
	else
		*line = ft_strndup(temp, -1);
}

void	ft_dependance(char *temp, char **line, char *buf)
{
	int	pos;
	int	i;

	i = 0;
	ft_position(line, pos = ft_strchr_int(temp, '\n'), temp);
	pos++;
	if (ft_strchr_int(buf, '\n') >= 0)
	{
		if (ft_strlen(temp) > BUFFER_SIZE)
		{
			while (temp[pos])
				temp[i++] = temp[pos++];
			temp[i] = '\0';
			ft_strcpy(buf, temp);
		}
		else
		{
			while (buf[pos])
				buf[i++] = buf[pos++];
			buf[i] = '\0';
		}
	}
	else
		buf[0] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	char		*temp;
	int			reed;

	line = NULL;
	reed = BUFFER_SIZE;
	temp = ft_strndup(buf, -1);
	if (fd < 0)
		return (ft_error(buf, temp), NULL);
	while (ft_strchr_int(buf, '\n') == -1 && reed == BUFFER_SIZE)
	{
		reed = read(fd, buf, BUFFER_SIZE);
		buf[reed] = '\0';
		if (reed <= 0)
		{
			if ((reed == 0 && buf[0] == '\0' && temp[0] == '\0') || reed == -1)
				return (ft_error(buf, temp), NULL);
		}
		else
			temp = ft_strjoin(temp, buf);
	}
	ft_dependance(temp, &line, buf);
	free(temp);
	return (line);
}

//int	main(void)
//{
//	int fd;
//	char *line;
//	int i;

//	i = 0;
//	fd = open("./lol.txt", O_RDONLY);
//	while (i <= 6)
//	{
//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);
//		i++;
//	}
//	return (0);
//}