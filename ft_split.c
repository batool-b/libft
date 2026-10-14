/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbaras <balbaras@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 10:55:09 by balbaras          #+#    #+#             */
/*   Updated: 2026/10/08 11:02:48 by balbaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_word(char const **s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, *s, len + 1);
	*s += len;
	return (word);
}

static void	free_words(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(result[i++]);
	free(result);
}

static int	fill_words(char **result, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		result[i] = get_word(&s, c);
		if (result[i] == NULL)
			return (i);
		i++;
	}
	result[i] = NULL;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		filled;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	filled = fill_words(result, s, c);
	if (filled != words)
	{
		free_words(result, filled);
		return (NULL);
	}
	return (result);
}
