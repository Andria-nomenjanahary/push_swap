/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:45:26 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/09 18:45:29 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	one_word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*one_word_cpy(char const *s, int start, int word_len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < word_len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**add_in_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		word_len;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			start = i;
			word_len = one_word_len(s, c, i);
			tab[j++] = one_word_cpy(s, start, word_len);
			i += word_len;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	add_in_tab(tab, s, c);
	return (tab);
}
