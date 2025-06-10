/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:48:57 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 14:55:18 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Compares two strings up to 'n' characters.
 *
 * Compares the first 'n' bytes of the strings 's1' and 's2'. Returns the 
 * difference between the first differing characters as unsigned char values.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n Maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if 's1' is 
 *         found to be less than, to match, or be greater than 's2'.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main(void)
{
	unsigned int	n;
	char			str1[] = "holA";
	char			str2[] = "hola";

	ft_strncmp(str1, str2, 1);
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d", strncmp("test\200", "test\0", 6));
	return (0);
}*/
