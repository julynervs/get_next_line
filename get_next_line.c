/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:45:29 by jurobert          #+#    #+#             */
/*   Updated: 2021/10/17 18:40:21 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer_backup(int fd, char *buffer, char *buffer_backup)
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
		if (!buffer_backup)
			buffer_backup = ft_strdup("");
		temp = buffer_backup;
		buffer_backup = ft_strjoin(temp, buffer);
	}
	free(temp);
	return (buffer_backup);
}

static char	*get_line(char *buffer_backup)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer_backup[i] != '\0' && buffer_backup[i] != '\n')
		i++;
	line = malloc(sizeof(char *) * (i + 1));
	ft_strlcpy(line, buffer_backup, i + 1);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*make_new_backup(char *buffer_backup)
{
	char	*new_backup;
	int		i;
	int		len_copy;

	i = 0;
	len_copy = ft_strlen(buffer_backup) - i + 1;
	new_backup = malloc(sizeof(char *) * len_copy);
	if (!new_backup)
		return (NULL);
	while (buffer_backup[i] != '\0' && buffer_backup[i] != '\n')
		i++;
	ft_strlcpy(new_backup, buffer_backup + i + 1, len_copy);
	free(buffer_backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer_backup = get_buffer_backup(fd, buffer, buffer_backup);
	if (!buffer_backup)
		return (NULL);
	line = get_line(buffer_backup);
	buffer_backup = make_new_backup(buffer_backup);
	return (line);
}
