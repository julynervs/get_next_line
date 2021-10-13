/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:45:29 by jurobert          #+#    #+#             */
/*   Updated: 2021/10/13 16:19:39 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, char *buffer, char *buffer_backup, char *line)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while ((!ft_strchr(buffer_backup, '\n')) && bytes_read)
	{
		if (!buffer_backup)
			buffer_backup = ft_strdup("");
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (bytes_read);
		buffer[bytes_read] = '\0';
		temp = buffer_backup;
		buffer_backup = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	buffer_backup = get_line(buffer_backup, line);
	return (bytes_read);
}

static char	*get_line(char *buffer_backup, char *line)
{
	int	i;
	char *new_backup;

	i = 0;
	while (buffer_backup[i] != '\n' && buffer_backup[i] != '\0')
		i++;
	line = ft_substr(buffer_backup, 0, i);
	new_backup = ft_substr(buffer_backup, i, ft_strlen(buffer_backup) + 1);
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
		return (NULL);
	bytes_read = read_file(fd, buffer, buffer_backup, line);
	if (!line && !bytes_read)
		return (NULL);
	return (line);
}
