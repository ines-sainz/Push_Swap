/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:01:51 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:55:05 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Duplicates a string by allocating memory and copying its content.
 *
 * Allocates sufficient memory for a copy of the string 's1', copies it, and  
 * returns a pointer to the new string.
 *
 * @param s1 The string to duplicate.
 * @return A pointer to the newly allocated copy of 's1',
 *         or NULL if memory allocation fails.
 */
char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new_string;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	new_string = malloc(len + 1);
	if (!new_string)
		return (NULL);
	new_string[len] = 0;
	while (i < len)
	{
		new_string[i] = s1[i];
		i++;
	}
	return (new_string);
}

/*int main(void)
{
    printf("%s\n", ft_strdup("asdfghjklñ"));
//    printf("%s\n", new_string);
	printf("%s\n", strdup("asdfghjklñ"));
}*/
