/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:21:27 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/11 08:58:13 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks if the character is alphanumeric (letter or digit).
 *
 * @param c The character to check.
 * @return 1 if c is a letter (a-z, A-Z) or digit (0-9), 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("El resultado del isalnum es: %d\n", isalnum(500));
	printf("MI ft_isalnum me da: %d\n", ft_isalnum(500));
}*/
