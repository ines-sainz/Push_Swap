/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:10:21 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/11 08:58:50 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks if the character is a digit (0 to 9).
 *
 * @param c The character to check.
 * @return 1 if c is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("El resultado del isdigit es: %d\n", isdigit(500));
	printf("MI ft_isdigit me da: %d\n", ft_isdigit(500));
}*/
