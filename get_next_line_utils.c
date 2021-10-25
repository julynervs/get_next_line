/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:26:48 by jurobert          #+#    #+#             */
/*   Updated: 2021/10/25 19:39:57 by jurobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = 0;
	while (s[len] != '\0')
		len++;
	copy = malloc(sizeof(char) * (len + 1);
	if (!copy && !s)
		return (NULL);
	copy[len] = '\0';
	while (len--)
		*copy++ = *s++;
	return (copy);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;
	while (*s != '\0' && *s != cc)
		s++;
	if (*s == cc || cc == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(&new[0], (char *)s1, i + 1);
	ft_strlcpy(&new[i], (char *)s2, i + j + 1);
	return (new);
}
