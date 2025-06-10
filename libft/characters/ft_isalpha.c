/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:55:06 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 09:53:42 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks if the character is an alphabetic letter.
 *
 * @param c The character to check.
 * @return 1 if c is a letter (a-z or A-Z), 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int main(void)
{
	printf("El resultado del isalpha es: %d\n ", isalpha(112));
	printf(" MI ft_isalpha me da: %d\n ", ft_isalpha(112));
}*/
