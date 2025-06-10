/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:43:41 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 09:57:32 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Convert an uppercase letter to lowercase.
 *
 * If the input character is an uppercase ASCII letter ('A' to 'Z'),
 * converts it to the corresponding lowercase letter ('a' to 'z').
 * Otherwise, returns the character unchanged.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent if uppercase, else the original character.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*int	main(void)
{
	printf("normal %c\n", tolower('U'));
	printf("la mia %c\n", ft_tolower('U'));
}*/
