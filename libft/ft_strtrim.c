/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:57:36 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/06 18:28:57 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_contain(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		srclen;
	int		k;

	srclen = 0;
	k = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	srclen = ft_strlen(s1);
	i = 0;
	while (s1[i] && is_contain(s1[i], set))
		i++;
	while (srclen > i && is_contain(s1[srclen - 1], set))
		srclen--;
	str = (char *)malloc(sizeof(char) * (srclen - i + 1));
	if (!str)
		return (NULL);
	while (i < srclen)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
