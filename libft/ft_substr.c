/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:57:57 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/07 14:35:00 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	srclen;
	char	*sub;

	if (!s)
		return (0);
	srclen = ft_strlen(s);
	if (s[0] == '\0' || start > srclen)
		return (ft_strdup(""));
	size = 0;
	if (start < srclen)
		size = srclen - start;
	if (size > len)
		size = len;
	sub = malloc(size + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}
