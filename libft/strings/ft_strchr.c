/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:46:24 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/29 18:36:24 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * Searches for the first occurrence of the character 'c' in the string 's'.
 *
 * @param s The string to search in.
 * @param c The character to search for, cast to unsigned char.
 * @return A pointer to the first occurrence of 'c' in 's',
 *         or NULL if 'c' is not found.
 *         If 'c' is '\0', returns a pointer to the null terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("hola", 'l'));
	printf("%s\n", strchr("hola", 'l'));
}*/
