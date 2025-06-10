/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:52:11 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/18 15:21:43 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Locates a substring in a string within a limited length.
 *
 * Searches for the first occurrence of the substring 'needle' in the string 
 * 'haystack', where not more than 'len' characters are searched. Characters 
 * after '\0' are not searched.
 *
 * @param haystack The string to be searched.
 * @param needle The substring to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the beginning of the located substring, or NULL if 
 *         the substring is not found within 'len' characters.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *) &haystack[i]);
	len_n = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (j == len_n - 1)
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

/*int	main(void)
{
	char	str1[20] = "hoolass";
	char	str2[20] = "ola";
	char	str3[20] = "hoolass";
	char    str4[20] = "ola";
	//ft_strstr (str1, str2, 3);
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 45));
	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 45));
	return (0);
}*/
