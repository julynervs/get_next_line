/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:45:29 by jurobert          #+#    #+#             */
/*   Updated: 2021/10/07 00:11:51 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_backup(int fd, char *backup, char *buffer)
{
	int		bytes;
	char	*temp;
	int		found;

	bytes = 1;
	found = 0;
	while (found == 0 || bytes != -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		if (ft_strchr(backup, '\n'))
			found = 1;
	}
	return (backup);
}

static char	*get_next_backup(char *backup)
{

}

static char	*get_line(char *backup)
{

}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	get_backup(fd, buffer);
}
