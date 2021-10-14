/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:45:29 by jurobert          #+#    #+#             */
/*   Updated: 2021/10/14 01:05:48 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_buffer_backup(int fd, char *buffer, char *buffer_backup)
{
	int		bytes_read;
	char	*temp;

	while ((ft_strchr(buffer, '\n') == NULL) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = buffer_backup;
		buffer_backup = ft_strjoin(temp, buffer);
	}
	free(temp);
	return (buffer_backup);
}

static char	*make_line(char *buffer_backup)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer_backup[i] != '\0' && buffer_backup[i] != '\n')
		i++;
	line = ft_substr(buffer_backup, 0, i);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	make_new_backup(char *buffer_backup)
{
	char	*new_backup;
	int		i;

	i = 0;
	while (buffer_backup[i] != '\0' && buffer_backup[i] != '\n')
		i++;
	new_backup = ft_substr(buffer_backup, i + 1, ft_strlen(buffer_backup) - i);
	free(buffer_backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_backup;
	int			bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer_backup = make_buffer_backup(fd, buffer, buffer_backup);
	if (!buffer_backup)
		return (NULL);
	line = get_line();
	buffer_backup = make_new_backup();
	return (line);
}
