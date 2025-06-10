/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:04:01 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 14:55:24 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Locate the last occurrence of a character in a string.
 *
 * Searches the string 's' for the last occurrence of the character 'c'.
 * The terminating null byte is considered part of the string.
 *
 * @param s The string to search in.
 * @param c The character to locate (converted to char).
 * @return Pointer to the last occurrence of 'c' in 's', or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strrchr("bonjourno", '\0'));
	printf("%s\n", strrchr("bonjourno", '\0'));
}*/
