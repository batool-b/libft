/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbaras <balbaras@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:00:04 by balbaras          #+#    #+#             */
/*   Updated: 2026/09/27 16:10:28 by balbaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*p;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		p[k++] = s1[i++];
	while (s2[j])
		p[k++] = s2[j++];
	p[k] = '\0';
	return (p);
}
