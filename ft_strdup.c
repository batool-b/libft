/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbaras <balbaras@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:13:42 by balbaras          #+#    #+#             */
/*   Updated: 2026/09/27 12:44:49 by balbaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	if (!s)
		return (NULL);
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
