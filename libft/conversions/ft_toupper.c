/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:21:46 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 10:02:10 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Convert a lowercase letter to uppercase.
 *
 * If the input character is a lowercase ASCII letter ('a' to 'z'),
 * converts it to the corresponding uppercase letter ('A' to 'Z').
 * Otherwise, returns the character unchanged.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent if lowercase, else the original character.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*int	main(void)
{
	printf("normal %c\n", toupper('u'));
	printf("la mia %c\n", ft_toupper('u'));
}*/
