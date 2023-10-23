/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <fdundar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:56:43 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/07 10:10:19 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ch;

	if (!s)
		return (0);
	len = ft_strlen(s);
	ch = malloc(len + 1);
	if (!ch)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ch[i] = (*f)(i, s[i]);
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
