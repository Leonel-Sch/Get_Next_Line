/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:49 by leonel            #+#    #+#             */
/*   Updated: 2024/07/02 19:11:39 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
	temp = ft_strndup(buffer, -1);
	if (fd < 0)
	{
		bzero(buffer, BUFFER_SIZE);
		free(temp);
		return (NULL);
	}
	if (ft_strchr_int(buffer, '\n') == -1)
	{
		while (ft_strchr_int(buffer, '\n') == -1 && reed == BUFFER_SIZE)
		{
			reed = read(fd, buffer, BUFFER_SIZE);
			buffer[reed] = '\0';
			if (reed <= 0)
			{
				if (reed == 0 && buffer[0] == '\0' && temp[0] == '\0')
				{
					bzero(buffer, BUFFER_SIZE);
					free(temp);
					return (NULL);
				}
				if (reed == -1)
				{
					bzero(buffer, BUFFER_SIZE);
					free(temp);
					return (NULL);
				}
			}
			else
				temp = ft_strjoin(temp, buffer);
		}
	}
	if ((pos = ft_strchr_int(temp, '\n')) >= 0)
		line = ft_strndup(temp, pos + 1);
	else
		line = ft_strndup(temp, -1);
	pos++;
	if (ft_strchr_int(buffer, '\n') >= 0)
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
	else
		bzero(buffer, BUFFER_SIZE);
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
//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//		close(fd);

//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//		fd = open("./lol.txt", O_RDONLY);

//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);

//	//while (i <= 6)
//	//{
//	//	line = get_next_line(fd);
//	//	printf("%s", line);
//	//	free(line);
//	//	i++;
//	//}
//	return (0);
//}