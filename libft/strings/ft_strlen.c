/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:33:11 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/12 17:46:57 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * Iterates through the string until the null terminator is found
 * and returns the number of characters.
 *
 * @param s The input string.
 * @return The number of characters in the string (excluding '\0').
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/*int	main(void)
{
	printf("El resultado del strlen es: %lu\n", strlen("qwertyiopasdfghjklñ"));
	printf("MI ft_strlen me da: %lu\n", ft_strlen("qwertyiopasdfghjklñ"));
}*/
