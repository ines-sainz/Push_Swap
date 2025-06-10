/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:20:22 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/30 21:00:17 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Frees an array of strings up to index j and returns NULL.
 *
 * @param new_string The array of strings to free.
 * @param j The last valid index to free.
 * @return NULL (for error handling convenience).
 */
static char	**ft_free_strings(char **new_string, int j)
{
	while (j >= 0)
	{
		free(new_string[j]);
		j--;
	}
	free(new_string);
	return (0);
}

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * @param s The input string to count words from.
 * @param c The delimiter character.
 * @return The number of words found.
 */
static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0')
			i++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j + 1);
}

/**
 * @brief Extracts a word from a string starting at *cont, skipping delimiters.
 *
 * @param s The source string.
 * @param c The delimiter character.
 * @param cont Pointer to current position in the string.
 * @return A newly allocated substring containing the word.
 */
static char	*fill(char const *s, char c, int *cont)
{
	int		j;
	char	*string;

	j = 0;
	string = NULL;
	while (s[*cont] == c && s[*cont])
		(*cont)++;
	j = *cont;
	while (s[*cont] != c && s[*cont])
		(*cont)++;
	string = ft_substr(s, j, *cont - j);
	return (string);
}

/**
 * @brief Splits a string into an array of substrings using a delimiter.
 *
 * @param s The input string to split.
 * @param c The delimiter character.
 * @return A NULL-terminated array of strings, or NULL on failure.
 */
char	**ft_split(char const *s, char c)
{
	int		cont;
	char	**string;
	int		count_words;
	int		i;

	i = 0;
	cont = 0;
	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	string = ft_calloc(count_words, sizeof(char *));
	if (string == NULL)
		return (free(string), NULL);
	while (i < count_words - 1)
	{
		string[i] = fill(s, c, &cont);
		if (!string[i])
			return (ft_free_strings(string, i));
		i++;
	}
	return (string);
}

/*int main(void)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split("holchochol", 'c');
	while (str[i])
	{
	    printf("%s\n", str[i]);
		i++;
	}
}
*/
