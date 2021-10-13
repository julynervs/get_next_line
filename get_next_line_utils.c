/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurobert <jurobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:26:48 by jurobert          #+#    #+#             */
/*   Updated: 2021/10/13 16:36:38 by jurobert         ###   ########.fr       */
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

	len = ft_strlen(s) + 1;
	copy = malloc(sizeof(char) * len);
	if (!copy && !s)
		return (NULL);
	while (len--)
		*copy++ = *s++;
	return (copy);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	sub_len;

	if (str)
	{
		str_len = ft_strlen(str);
		sub_len = len;
		if (start >= str_len)
			return (ft_strdup(""));
		else if (start + len >= str_len)
			sub_len = str_len - start;
		substr = malloc((sub_len + 1) * sizeof(char));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, (str + start), sub_len + 1);
		return (substr);
	}
	return (NULL);
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
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
