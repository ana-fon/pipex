/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:25:54 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/14 13:25:56 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	count_words(char const *s, char c);
static char	**add_words(char **array, char const *s, char c, int n);
static char	*ft_strndup(char const *s, char c);
static char	**free_memory(char **array, int n);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		size;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	array = malloc((size + 1) * (sizeof (char *)));
	if (!array)
		return (NULL);
	return (add_words(array, s, c, size));
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**add_words(char **array, char const *s, char c, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			array[j] = ft_strndup(&s[i], c);
			if (!array[j])
				return (free_memory(array, j));
		}
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	array[j] = NULL;
	return (array);
}

static char	*ft_strndup(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc ((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**free_memory(char **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
